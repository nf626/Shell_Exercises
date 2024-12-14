#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct path {
  char *str;
  struct path *next;
} path_t;

void print_list(const path_t *h)
{
  while (h != NULL)
    {
      if (h->str == NULL)
	{
	  printf("[0] (nil)\n");
	  h = h->next;
	}
      else
	{
	  printf("%s\n", h->str);
	  h = h->next;
	}
    }
}

path_t *add_node_end(path_t **head, const char *str)
{
  path_t *current = NULL;
  path_t *last = NULL;
  
  last = malloc(sizeof(path_t));
  if (last == NULL)
    {
      free(last);
      return (NULL);
    }
  last->str = strdup(str);
  last->next = NULL;
  if (*head == NULL)
    {
      *head = last;
      return (last);
    }
  else
    {
      current = *head;
      while (current->next != NULL)
	{
	  current = current->next;
	}
      current->next = last;
    }
  return (current);
}

void free_list(path_t *head)
{
  path_t *temp = NULL;

  while (head != NULL)
    {
      temp = head;
      head = head->next;
      free(temp->str);
      free(temp);
    }
  free(head);
}
