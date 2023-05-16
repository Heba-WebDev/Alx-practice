#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main -interactive shell
 *
 * Return: 0 (Success)
 */

int main(void)
{
	char *command = NULL, *args[2], *token;
	size_t command_len = 0;
	int status;
	pid_t pid = fork();

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (getline(&command, &command_len, stdin) == -1)
			break;

		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			continue;
		}
		if (strcmp(command, "exit") == 0)
		{
			break;
		}
		token = strtok(command, " \n");
		args[0] = token;
		args[1] = NULL;

		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			int i = 0;

			while (token != NULL)
			{
				args[i] = token;
				i++;
				token = strtok(NULL, " ");
			}
			args[i] = NULL;
			execvp(args[0], args);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else
			waitpid(pid, &status, 0);
	}
	free(command);
	return (0);
}
