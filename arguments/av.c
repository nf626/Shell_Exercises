#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all the arguments, without using ac.
 * @ac: number of items in av.
 * @av: NULL terminated array of strings.
 *
 * Return: 0 success.
 */
int main(int ac, char **av)
{
  int count = 0;
  
  while (av[count] != NULL)
    {
      printf("%s\n", av[count]);

      count++;
    }
  return (0);
}
