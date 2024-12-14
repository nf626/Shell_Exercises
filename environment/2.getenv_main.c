#include "environ.h"
#include <stdio.h>

/**
 * main - Prints out environment list.
 *
 * Return: 0, Success.
 */
void main()
{
  char *name;

  name = _getenv("PATH");
  
  printf("Environment: %s\n", name);
}
