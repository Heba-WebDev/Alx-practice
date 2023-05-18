#include "shell.c"
#include <stdlib.h>
#include <stdio.h>
#include "env_builtin.h"

/**
 * print_environment - prints current environment
 *
 * Return: 0 (Success);
 */

int print_environment()
{
	int i;

	for (int i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
