#ifndef ENVIRONMENT_HEADER
#define ENVIRONMENT_HEADER
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct path {
  char *str;
  struct path *next;
} path_t;

void print_list(const path_t *h);
path_t *add_node_end(path_t **head, const char *str);
void free_list(path_t *head);

#endif
