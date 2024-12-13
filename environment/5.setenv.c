#include <stdio.h>
#include <stdlib.h>

extern char **environ;
/**
 * _setenv - changes or adds an environment variable
 *           (without using setenv).
 * @name: adds the variable name to the environment.
 * @value:
 * @overwrite:
 *
 * Return: zero on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
  char *copy = malloc(sizeof(char *));
  if (copy == NULL)
    {
      free(copy);
      return (-1);
    }
  if (getenv(name) == 1)
    {
      if (overwrite == 0)
	{
	}
      else if (overwrite > 0)
	{
	  replace value
	}
      return (0);
    }
  else
    {
      perror("Error:");
      return (-1);
    }
}

int main()
{
  char newvar[] = "language";
  char value[] = "C";
  
  _setenv(newvar, value, 1);
  
  printf("Result: %s\n", getenv(newvar));
  
  return (0);
}
