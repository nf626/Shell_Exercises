#include "environ.h"

/**
 * main - function that changes or adds an environment
 *        variable (without using setenv).
 *
 * Return: 0, Success.
 */
int main()
{
  char *env = _getenv("TEST");
  char *new_env;

  _setenv("TEST", "Changed", 1);
  new_env = _getenv("TEST");
  
  printf("Result: %s\n", new_env);
  
  return (0);
}
