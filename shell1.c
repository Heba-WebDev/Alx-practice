#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>



/**
 * main - entry point to the program
 *
 * Return: (0) on success and (-1) on failure
 */


int main(void)
{
int argc = 0;
size_t n = 0;
char* buffer = NULL;

//prompt user to enter a command and add new line
printf("$ \n");

//capture the promt with getline
getline(&buffer, &n, stdin);

//now we need to make sure
printf("Your name is %s and buffer size is %ld \n", buffer, n);

//the delimter
const char s[2] = " ";

char *token;

/* get the first token which is a pointer to a string */
token = strtok(buffer, s);
int value = execve(buffer[0], buffer, NULL);

if (value == -1)
{
perror("Error");
}

while (token)
{
argc++;
}

if (argc > 1)
{
perror("Error");
}

if (argc == 1)
{

}

free(buffer);
return (0);
}
