
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: the number of char they don't have in common
*/

int _strcmp(const char *s1, const char *s2)
{
while (*s1 && *s2 && *s1 == *s2)
{
s1++;
s2++;
}
return (*s1 - *s2);
}
