#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - function that splits a string and returns
 *        an array of each word of the string.
 *
 * Return: 0, Success.
 */
int main()
{
  char *buffer;
  size_t buffsize = 64;
  size_t characters;
  char *token;

  buffer = malloc(sizeof(buffsize) * sizeof(char *));
  if (buffer == NULL)
    {
      free(buffer);
      exit(1);
    }
  while (1)
    {
      printf("$ ");
      characters = getline(&buffer, &buffsize, stdin);
      printf("%s\n", buffer);
      printf("Buffer size: %zu\n", characters);
      
      token = strtok(buffer, " ");
      while (token != NULL)
	{
	  printf("buffer string token: %s\n", token);
	  token = strtok(NULL, " ");
	}
       printf("Ctrl + C to Exit\n");
    }
  free(buffer);
  return (0);
}
