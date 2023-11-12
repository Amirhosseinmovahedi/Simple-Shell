#include "shell.h"

/**
 * own_cd - changes the working dir of the current shell executon env
 * @args: target directory
 *
 * Return: -1 on success, 0 on failure.
 */
int own_cd(char **args)
{
	int chdir_status = chdir(args[1]);
	if (chdir_status != 0) {
		perror("error");
	}

    return -1;
}
