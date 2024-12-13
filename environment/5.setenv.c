#include <stdio.h>
#include <stdlib.h>

/**
 * _setenv - changes or adds an environment variable
 *           (without using setenv).
 * @name:
 * @value:
 * @overwrite:
 *
 * Return: zero on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
  putenv("name");
  if ()
    {
      return (-1);
    }
  return (0);
}

int main()
{
  char *env_var = getenv("TEST");
  printf("%s\n", env_var);
  
  _setenv("TEST", "Variable has changed", 0);
  setenv("TEST2", "Changed", 1);

  char *new = getenv("TEST2");
  printf("%s\n", new);
  return (0);
}
