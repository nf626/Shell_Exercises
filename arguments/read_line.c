#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints the user input to next line.
 * 
 * Return: 0, Success. 
 */
int main()
{
  char *buffer;
  size_t buffsize = 64;
  size_t characters;

  buffer = malloc(sizeof(buffsize) * sizeof(char));
  if (buffer == NULL)
    {
      free(buffer);
      exit(1);
    }

  while (1)
    {
      printf("$ ");
      characters = getline(&buffer, &buffsize, stdin);
      printf("%s", buffer);
      printf("buffer size: %zu\n", characters);
      printf("Ctrl + C or Ctrl + D to Exit\n");
    }
  free(buffer);
  return (0);
}
