/*
Task
  Write a C program that accomplishes the following tasks:
  - Create a child process from the main process.
  - Force the child process open a file named "Name.txt" (creating it if it doesn't exist) and write the string "System programming" to it.
  - Ensure that the parent process waits until the child process finishes execution.
  - After the child process has finished, the parent process should open the same file and append your name to it on a new line.
  
**Again, beware of my lazy error handling.**
*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int f1, f2;
  const char *name = "Ahmad MAhmoud";
  const char *course = "Systems Programming";
  pid = fork();
  if (pid < 0) {
    // Error
  } else if (pid == 0) {
    f1 = open("Name.txt", O_RDWR | O_CREAT, 0644); // open or create the first file
    if (f1 == -1) {
      printf("Error opening or creating file1");
      exit(1);
    }
    write(f1, course, strlen(course));
    close(f1);

  } else {
    // Parent
    wait(NULL);
    f2 = open("Name.txt", O_APPEND | O_RDWR, 0644); // open or create the first file
    if( f2 == -1){
      printf("Error Opening or creating file2");
      exit(1);
    }
    
    write(f2, "\n", strlen("\n"));
    write(f2, name, strlen(name));
  }
    close(f2);

  return 0;
}
