#include "shell.h"


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
handle_path(command);
pid = fork();
process(pid, args, status);
}
free(command);
return (0);
}


