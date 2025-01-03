#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * _which - Check files if in the current PATH.
 * @filename: filename to check.
 *
 */
void _which(char *filename)
{
  if (access(filename, F_OK) == 0)
    {
      printf("%s: File is found\n", filename); 
    }
  else
    {
      printf("%s: No file found\n", filename);
    }
}
/**
 * main - program that looks for files in the current PATH.
 *
 * Return: 0, Success.
 */
int main(void)
{
  char *buffer = NULL;
  char *token;
  size_t buffersize = 0;

  while (1)
    {
      write(1, "#cisfun$ ", 9);
      getline(&buffer, &buffersize, stdin);
      token = strtok(buffer, " \t\n");
      if (strcmp(token, "which") == 0)
	{
	  token = strtok(NULL, " \t\n");
	  while (token)
	    {
	      _which(token);
	      token = strtok(NULL, " \t\n");
	    }
	}
      else
	{
	  printf("File does not match\n");
	}
    }
  return (0);
}
