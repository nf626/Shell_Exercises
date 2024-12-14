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
  char *env_var = _getenv(name);

  if (name == NULL || value == NULL || overwrite == NULL)
    {
      perror("Error:");
      return (-1);
    }
  
  if (name is there);
    {
      if (overwrite == 0)
	{
	  value of name is not changed;
	  return (0);
	}
      else
	{
	  print_list(name);
	  return (0);
	}
}
