#include "environ.h"

/**
 * _setenv - changes or adds an environment variable
 *           (without using setenv).
 * @name: variable name to the environment.
 * @value: variable value to name.
 * @overwrite: zero or not zero.
 *
 * Return: zero on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
  char *current_env;
  char **copy_env = environ, **new_env;
  size_t i, j;
 /** Make new environment variable with format NANME=Value */
  size_t name_length = strlen(name), value_length = strlen(value);
  size_t env_length = name_length + value_length + 2;

  if (name == NULL || value == NULL)
    {
      perror("Error:");
      return (-1);
    }

  current_env = malloc(env_length);
  if (current_env == NULL)
    {
      free(current_env);
      return (-1);
    }

  
  while ((*copy_env) != NULL)
    {
      if ((strncmp((*copy_env), name, name_length) == 0) && ((*copy_env)[name_length] == '='))
	{
	  if (overwrite)
	    {
	      (*copy_env) = current_env;
	      return (0);
	    }
	  else
	    {
	      free(current_env);
	      return (0);
	    }
	}
      copy_env++;
    }
  new_env = realloc(environ, (sizeof(environ) / sizeof(char *) + 1) * sizeof(char *));
  if (new_env == NULL)
    {
      free(current_env);
      return (-1);
    }

  new_env[sizeof(environ) / sizeof(char *)] = current_env;
  environ = new_env;
  
  return (0);
}
