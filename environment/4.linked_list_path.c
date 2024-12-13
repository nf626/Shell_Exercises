#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct path
{
  char *str;
  struct path *next;
} path_t;

int main()
{
  unsigned int i = 0;
  char *pathname;
  char *token;
  
  pathname = getenv("PATH");
  token = strtok(pathname, ":");

  while (token != NULL)
    {
      printf("%s", token); 
      token = strtok(NULL, ":");
    }
}
