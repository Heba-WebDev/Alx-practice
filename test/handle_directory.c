#include "shell.h"


/**
 * handle_directory - change directories
 * @args: array of arguments
 * Return: void
 */

void handle_directory(char **args)
{
if (args[1] == NULL)
{
write(STDERR_FILENO, "cd: missing argument\n", 20);
}
else if (chdir(args[1]) != 0)
{
perror("cd");
}
}
