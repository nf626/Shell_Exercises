#include <stdio.h>
#include <unistd.h>

extern char **environ;

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
  printf("address of env = %p\n", env);
  printf("address of environ = %p\n", environ);

  return (0);
}
