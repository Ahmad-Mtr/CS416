#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/*
Write a C program to implement the following processes:
1- A is the parent process which will print its process id and print a sentence that it is the parent.
2- B is the child of A, that print its process id and its parent process id, then call the execl() to list all files in
the directory.
3- C is the child of B, that will print its process id and its parent process id, then call the execv() to create
directory.
4- Make sure that the parent does not close before the child is done.
*/

// Note: that exec removes what's left in the code, meaning if i putted exec in B before forking, C won't be created, look at the exec, and waitpid() ordering
int main() {
  pid_t pid = fork();
  if (pid != 0) {
    // #Q1
    // parent
    printf("\n*parent**************************\nParent id: %d\n", getpid());
    waitpid();
  } else {
    // #Q, 
    // child
    printf("\n*child B*************************\nChild (B) id: %d\t parent id: "
           "%d\n",
           getpid(), getppid());
    char *args1[] = {"ls", "-aF", "/", NULL};
    char *env[] = {NULL};
    printf("about to run bin /ls\n");

    waitpid();
    pid_t pid2 = fork();
    if (pid2 == 0) {
      // c
      printf("\n******C************\nC iD: %d\tParent id: %d\n", getpid(),
             getppid());
      char *args[] = {"mkdir", "testsssssss", NULL};
      char *env[] = {NULL};
      printf("about to run bin CC /mkdir\n");
      execv("/bin/mkdir", args);
      printf("Error\n");
    } else if (pid2 < 0)
      printf("ERRORR\n");
    else {
      execl("/bin/ls", args1, env);
    }
  }
  return 0;
}
