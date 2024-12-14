#include "environ.h"

/**
 * main - function that builds a linked list of the PATH directories.
 *
 * Return: 0, Success.
 */
int main()
{
  unsigned int i = 0;
  char *pathname, *token;
  path_t *head = NULL;
  
  pathname = getenv("HOME");
  token = strtok(pathname, ":");
 
  while (token != NULL)
    {
      add_node_end(&head, token);
      token = strtok(NULL, ":");
    }
  print_list(head);
  free_list(head);
  head = NULL;
  return (0);
}
