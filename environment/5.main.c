#include "environ.h"

/**
 * main - Prints out set environment variables.
 *
 * Return: 0, Success.
 */
int main()
{
  char *env = getenv("TEST");
  setenv("TEST", "Changed", 1);
  
  char *new_env = getenv("TEST");
  printf("Set environment: %s\n", new_env);

  return (0);
}
