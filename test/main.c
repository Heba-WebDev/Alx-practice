#include "shell.h"


/**
 * main - entry to the program
 *@argc: the number of arguments
 *@argv: a pointer to an array of arguments
 *
 * Return: (0)
*/


int main(int argc, char **argv)
{

char *command = NULL, *token, *args;
size_t command_len = 0;
int i = 0, status;

while (1)
{
printf("$ ");
fflush(stdout);

if (getline(&command, &command_len, stdin) == -1)
{
break;
}
if (_strcmp(command, "/n") == 0)
{
continue;
}
token = strtok(command, " \n");

while (token != NULL)
{
args[i++] = token;
token = strtok(NULL, " \n");
}
args[i] = NULL;

if (_strcmp(args[0], "exit") == 0)
{
break;
}

pid_t pid = fork();
newprocess(pid, args, status);
}

free(command);
return (0);
}



/**
 * newprocess - fork new process
 * @pid: the new process
 * @args: the arguments
 * @status: status of the process
 * Return: void
*/


void newprocess(pid_t pid, char *args, int status)
{
if (pid == -1)
{
perror("fork");
exit(1);
}
else if (pid == 0)
{
execvp(args[0], args);
perror("Error");
_exit(1);
}
else
{
waitpid(pid, &status, 0);
}
}
