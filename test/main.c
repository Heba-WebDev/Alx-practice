#include "shell.h"
void process(pid_t pid, char **args, int status);
/**
 * main - interactive shell
 *
 * Return: (0)
 */

int main(void)
{
char *command, *token, *args[1024];
size_t command_len = 0;
int i = 0, status = 0;
pid_t pid;
while (1)
{
printf("$ ");
fflush(stdout);

if (getline(&command, &command_len, stdin) == -1)
{
break;
}

token = strtok(command, " \n");
i = 0;
while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " \n");
}
args[i] = NULL;

if (args[0] != NULL && _strcmp(args[0], "exit") == 0)
{
break;
}

pid = fork();
process(pid, args, status);
}
free(command);
return (0);
}


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
perror("execvp");
_exit(EXIT_FAILURE);
}
else
{
waitpid(pid, &status, 0);
}
}
