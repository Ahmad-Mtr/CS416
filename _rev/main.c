
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
<<<<<<< HEAD
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
=======
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Create an array to hold the command and its arguments
    char *args[] = {"git", "status", NULL};

    // Execute the git status command using execvp
    if (execvp("git", args) == -1) {
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }

    // This code will only be reached if execvp fails
    printf("This line will not be executed\n");
    return 0;
}
>>>>>>> 088ad557710066cf4d258f186a565156389f8b1d
