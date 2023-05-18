#include "shell.c"
#include <stdio.h>
#include <string.h>

/**
 * handle_comments - removes comments from the command
 * @command: command to be handled
 */

void handle_comments(char *command)
{
	char *comment_position = strchr(command, '#');

	if (comment_position != NULL)
	{
		comment_position = '\0';
	}
}
