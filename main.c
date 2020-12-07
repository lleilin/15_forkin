#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main () {
  printf("Before Forking\n");
  srand(time(NULL));
  int f = fork();
  if (f) {
    rand();
    f = fork();
  }

  if (f) {
    int status;
    int pid = wait(&status);
    printf("Child finished\t PID: %d\t Time: %ds\n", pid, WEXITSTATUS(status));
    printf("Parent finished\n");
    return 0;
  } else {
    printf("Child running \t PID: %d\n",getpid());
    int temp = rand() % 8 + 2;
    sleep(temp);
    printf("Child finished\t PID: %d\n", getpid());
    return temp;
  }
}
