#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100

/**
 * main - Entry point fo program
 *
 * Return: 0 (Success)
 */

int main()
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		if (fgets(command, sizeof(command), stdin) == NULL)
		{
			break;
		}

		command[strcspn(command, "\n")] = '\0';

		if (strlen(command) == 0)
		{
			continue;
		}

		if (strcmp(command, "exit") == 0)
		{
			break;
		}

		pid_t child_pid = fork();

		if (child_pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}

		else if (child_pid == 0)
		{
			char *args[MAX_COMMAND_LENGTH];
			char *token = strtok(command, " ");
			int i = 0;

			while (token != NULL)
			{
				args[i] = token;
				i++;
				token = strtok(NULL, " ");
			}

			args[i] = NULL;

			execvp(args[0], args);
			perror("exec");
			exit(EXIT_FAILURE);
		}

		else
		{
			int status;
			waitpid(child_pid, &status, 0);
			printf("\n");
		}
	}

	return (0);
}
