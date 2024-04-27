/******************************************************************************
Write a C program to implement the following simple tree of processes:
- A forks B and C.
- B and C have the same parent ID.
- For each process, print its name, its PID, and it is Parent PID.
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  pid_t pid_A, pid_B, pid_C;
  pid_A = getpid();
  printf("This is process A with id: %d\n", pid_A);

  pid_B = fork();
  if (pid_B < 0) {
    printf("Fork B failed");
    exit(1);
  } else if (pid_B == 0) {
    printf("This is process B with id: %d, and parent id: %d\n", getpid(),
           getppid());
    exit(0);
  } else {
    pid_C = fork();
    if (pid_C < 0) {
      printf("Fork C failed");
      exit(1);
    } else if (pid_C == 0) {
      printf("This is process C with id: %d, and parent id: %d\n", getpid(),
             getppid());
      exit(0);
    }
    wait(NULL);
    wait(NULL);
  }
  return 0;
}
