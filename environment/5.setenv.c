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
  char *new_env;
  char **copy_env = environ;
  size_t i, j;
 /** Make new environment variable with format NANME=Value */
  size_t name_length = strlen(name), value_length = strlen(value);
  size_t env_length = name_length + value_length + 2;

  if (name == NULL || value == NULL)
    {
      perror("Error:");
      return (-1);
    }

  new_env = malloc(env_length);
  if (new_env == NULL)
    {
      free(new_env);
      return (-1);
    }
  
  while ((*copy_env) != NULL)
    {
      if (strcmp()
    }
}
