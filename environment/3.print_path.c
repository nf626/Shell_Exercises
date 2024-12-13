#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * main - prints each directory contained in the the 
 *        environment variable PATH, one directory per line.
 *
 * Return: 0, Success.
 */
int main()
{
  char *pathname;
  char *token;

  pathname = getenv("PATH");
  token = strtok(pathname, ":");

  while (token != NULL)
    {
      printf("%s\n", token);
      token = strtok(NULL, ":");
    }
  return (0);
}
