#include "environ.h"

extern char **environ;

/**
 * _getenv - Function searches the environment list to find the
 *           environment variable name, and returns a pointer to the
 *           corresponding value string.
 * @name: Environment variable name.
 *
 * Return: a pointer to the value in the
 *         environment, or NULL if there is no match.
 */
char *_getenv(const char *name)
{
  unsigned int i = 0;
  char *token;
  
  while(environ[i] != NULL)
    {
      token = strtok(environ[i], "=");
      if (strcmp(token, name) == 0)
	{
	  token = strtok(NULL, "=");
	  return (token);
	}
      i++;
    }
  return (NULL);
}
