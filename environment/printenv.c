#include <stdio.h>
#include <unistd.h>

extern char **environ;

/**
 * main - program that prints the environment
 *        using the global variable environ.
 *
 * Return: 0, Success.
 */
int main()
{
    unsigned int i;

    i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
    return (0);
}
