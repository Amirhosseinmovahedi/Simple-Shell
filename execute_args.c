#include "shell.h"

int execute_args(char **args)
{
	pid_t pid;
	int status;
	char *builtin_func_list[] = {
		// you should add something here
		"exit", "cd"
	};
	int (*builtin_func[])(char **) = {
		// you should add something here
		&own_exit, &own_cd
	};

	long unsigned int i = 0;
	for (; i < sizeof(builtin_func_list) / sizeof(char *); i++)
	{
		/* if there is a match execute the builtin command */
		if (strcmp(args[0], builtin_func_list[i]) == 0)
		{
			return ((*builtin_func[i])(args));
		}
	}

	pid = fork();
	if (pid < 0){
		printf("fork failure.\n");
		return 0;
	} else if (pid == 0){
		int status_code = execvp(args[0], args);
		if (status_code == -1){
			exit(-1);
		}
	} else {
		pid_t pid_wait = waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) == 255) // -1 in 8 bit
        {
			printf("err: this command can not be executed.\n");
        }
	}

	return (-1); // this status code means everything is ok
}
