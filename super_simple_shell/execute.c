#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Run execve to execute another program.
 *
 * Return: 0, Success.
 */
int main()
{
  char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
  char *env[] = {NULL};
   
    printf("Before execve\n");
    printf("==================================================================================================\n");
    if (execve(argv[0], argv, env) == -1)
    {
        perror("Error:");
    }
    printf("Oops, something went wrong\n");
    return (0);
}
