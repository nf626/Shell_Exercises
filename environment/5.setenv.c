#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
/**
 * _setenv - changes or adds an environment variable
 *           (without using setenv).
 * @name: variable name to the environment.
 * @value: variable value to name.
 * @overwrite: zero or not zero.
 *
 * Return: zero on success, or -1 on error.
 */
int _setenv(const char *name, const char *value, int overwrite)
{
  int i = 0, len = 0;
  char *new_var;

  if (name == NULL || value == NULL)
    {
      return (-1);
    }
  while (environ[i] != NULL)
    {
      len = strlen(name);
      if (strncmp(environ[i], name, len) == 0)
	{
	  /** If name does exist in the environment, then its value is changed to value */
	  if (overwrite != 0)
	    {
	      new_var = malloc(sizeof(char *) * 1024);
	      strcpy(new_var, name);
	      strcat(new_var, "=");
	      strcat(new_var, value);
	      environ[i] = new_var;
	      return (0);
	    }
	  return (0);
	}
      i = i + 1;
    }
  new_var = malloc(sizeof(char *) * 1024);
  strcpy(new_var, name);
  strcat(new_var, "=");
  strcat(new_var, value);
  environ[i] = new_var;
  environ[i + 1] = NULL;
  return (0);
}

char *_getenv(char *env_var)
{
  int i = 0;
  char *name;

  while (environ[i] != NULL)
    {
      name = strtok(environ[i], "=");
      if(strcmp(env_var, name) == 0)
	{
	  name = strtok(NULL, "\n");
	  return (name);
	}
      i = i + 1;
    }
  return (NULL);
}

char *get_command(char *command)
{
  char *path, *token, *cmd;
  struct stat st;

  path = _getenv("PATH");
  token = strtok(path, ":");
  while (token != NULL)
    {
      cmd = malloc(sizeof(char *) * 1024);
      strcpy(cmd, token);
      strcat(cmd, "/");
      strcat(cmd, command);
      if (stat(cmd, &st) == 0)
	{
	  return (cmd);
	}
      free(cmd);
      token = strtok(NULL, ":");
    }
  return (NULL);
}

char **split_string(char * buffer, char *del)
{
  char **tokens;
  char *token;
  int i = 0;

  tokens = malloc(sizeof(char *) * 1024);
  token = strtok(buffer, del);
  while (token != NULL)
    {
      tokens[i] = token;
      token = strtok(NULL, del);
      i = i + 1;
    }
  tokens[i] = NULL;
  return (tokens);
}

int main(int argc, char **argv, char **env)
{
  char *buffer = NULL, *cmd;
  size_t buffer_size = 0;
  char **args;
  pid_t pid;
  int status, n_chars;
  
  while (1)
    {
      printf("#cisfun$ ");
      n_chars = getline(&buffer, &buffer_size, stdin);
      if (n_chars == -1)
	{
	  perror("Error:");
	  exit(2);
	}
      args = split_string(buffer, " \t\n");
      if (strcmp(args[0], "exit") == 0)
	{
	  exit(0);
	}
      pid = fork();
      if (pid == 0)
	{
	  cmd = get_command(args[0]);
	  if (cmd)
	    {
	      execve(cmd, args, env);
	    }
	  else
	    {
	      printf("Command not found\n");
	    }
	  exit(0);
	}
      else
	{
	  wait(&status);
	}
    }
  return (0);
}
