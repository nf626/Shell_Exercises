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
}

int main()
{
  char *env_var = getenv("TEST");

  setenv("TEST", "Changed", 1);

  char *new = getenv("TEST");
  printf("%s\n", new);
  return (0);
}
