/*
 * A basic code (for Linux) that demonstrates the use of basic process resources.
 * This code creates a child process using fork() and executes another program using execvp().
 * A Basic summary of probably unfamiliar functions:
 *      fprintf(): Prints formatted data to a stream (usually stderr in this case).
 *      execvp(): Executes a file with the given name, replacing the current process image.
 * NOTE: This code won't work on Windows (`fork()` isn't available).
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
void spawn(char* program, char **arglist){
  pid_t pid;
  pid = fork();
  if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        exit(1);
    } else if (pid == 0) {
        execvp(program, arglist);
        fprintf(stderr, "Error executing program\n");
        exit(1);
    } else {
        printf("************Run\n");
    }

}

int main(){
   char *arglist[] = {"mkdir", "tmp_dir", NULL};
  spawn(arglist[0], arglist);
  printf("Done with the Main Program\n");

  return 0;
}
