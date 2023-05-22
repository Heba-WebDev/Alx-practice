#include "shell.h"

/**
 * process - creates a new process
 *@pid: the process
 *@args: the array of arguments
 *@status: process id
 * Return: void
 */

void process(pid_t pid, char **args, int status)
{
if (pid == -1)
{
perror("fork");
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
execvp(args[0], args);
perror("./hsh");
_exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}

