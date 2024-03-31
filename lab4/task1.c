#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
// TASK: Create 3 Folders inside each other, C in it, B, init, A. 
/* C->B->A */
// NOTE: The output Directories should be as <C> & its children.
int main(){

  printf("Process A\n");
  pid_t pid1;
  // Fork Part
  pid1 = fork();
  if ( pid1 < 0){
    printf("Errorr\n");
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
