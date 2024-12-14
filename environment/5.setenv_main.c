#include "environ.h"

/**
 * main - function that changes or adds an environment
 *        variable (without using setenv).
 *
 * Return: 0, Success.
 */
int main()
{
  char newvar[] = "language";
  char value[] = "C";
  
  _setenv(newvar, value, 1);
  
  printf("Result: %s\n", getenv(newvar));
  
  return (0);
}
