/*
  Create Program that triggers a system call to mkdir C in it B in it A.
  .
  ├── C
  │   └── B
  │       └── A
  ├── task.c
  └── they_say_this_is_exe
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  printf("Process A\n");
  pid_t pid1;
  // Fork Part
  pid1 = fork();
  if (pid1 < 0) {
    printf("Errorr\n");
  } else if (pid1 > 0) {
    // Parent A
  } else {
    // Child B
    pid_t pid2 = fork();
    if (pid2 == 0) {
      // C
      execl("/bin/mkdir", "mkdir", "C", NULL);
      exit(1);
    } else {
      // B
      wait(NULL);
      execl("/bin/mkdir", "mkdir", "C/B", NULL);
      exit(1);
    }
  }
  // Folder Part
  wait(NULL);
  execl("/bin/mkdir", "mkdir", "C/B/A", NULL);
  return 0;
}
