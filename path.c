#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "promp.h"

#define MAX_COMMAND_LENGTH 100
#define MAX_PATH_LENGTH 100

void hanlde_path(const char *command)
{
	char path[MAX_PATH_LENGTH];
	int found = 0;
	const char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		snprintf(path, sizeof(path), "%s/%s", token, command);
		if (access(path, X_OK) == 0)
		{
			found = 1;
			break;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);

	if (found)
	{
		pid_t pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			char *args[MAX_COMMAND_LENGTH];
			args[0] = strdup(path);
			args[1] = NULL;
			execve(path, args, environ);
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
	else
	{
		printf("Command not found: %s\n\n", command);
	}
}
