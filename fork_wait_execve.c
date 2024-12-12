#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - program that executes the command ls -l /tmp
 *        in 5 different child processes. Each child
 *        should be created by the same process (the father).
 *        Wait for a child to exit before creating a new child.
 *
 * Return: Always 0.
 */
int main()
{
  pid_t pid, init_pid;
  int status;
  int count = 5, i = 0;
  char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
  char *envp[] = {NULL};

  printf("Execve program\n");
  printf("=================================================\n");
  init_pid = getppid();
  printf("init pid: %u\n", init_pid);

  while (i < count)
    {
      pid = fork();
      if (pid == -1)
	{
	  perror("Error:");
	  exit(-1);
	}
    	if (pid == 0)
	{
	  printf("Child process: PPID = %u, PID = %u\n", getppid(), getpid());
	  if (execve(argv[0], argv, envp) == -1)
	    {
	      perror("Error:");
	    }
	  execve(argv[0], argv, envp);
	  exit(0);
	}
      else
	{
	  printf("Parent process: PID = %u\n", getpid());
	  printf("Waiting for Child processes to finish...\n");
	  wait(&status);
	  printf("Child process is finished.\n");
	}
      i = i + 1;
    }
     
  printf("Execve has finished.\n");
  
  return (0);
}
