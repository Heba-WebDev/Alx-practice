#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.c"

#define MAX_PATH_LENGTH 100

extern char **environ;

void handle_path(const char *command)
{
	char path[MAX_PATH_LENGTH];
	const char *path_env = getenv("PATH");
	char *path_copy = strdup(path_env);
	char *token = strtok(path_copy, ":");

	while (token != NULL)
	{
		snprintf(path, sizeof(path), "%s/%s", token, command);
		if (access(path, X_OK) == 0)
		{
			break;
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return;
}
