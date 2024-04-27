// TASK: Create 3 Folders inside each other, C in it, B, init, A. 
/* C->B->A 
  .
  ├── C
  │   └── B
  │       └── A
  ├── task1.c
*/
// NOTE: The output Directories should be as <C> & its children.
//     **I'm lazy to handle all errors or print Processes Data, don't take it seriously and always write better code.**

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){

  printf("Process A\n");
  pid_t pid1;
  // Fork Part
  pid1 = fork();
  if ( pid1 < 0){
    printf("Errorr\n");
    return 1;
  }else if(pid1 > 0){
    // Parent A
  }else{
    // Child B
    pid_t pid2 = fork();
    if (pid2 == 0){
      //C
      execl("/bin/mkdir", "mkdir", "C", NULL);
      exit(1);
    }else{
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
