#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 250
int main() {
  pid_t pid;
  int f1, f2;
  off_t _offset;
  ssize_t numByteRead, numByteWritten;
  char buffer[BUF_SIZE];
  const char *name = "\nAhmad MAhmoud";
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
    write(f2, name, strlen(name));
  }
    close(f2);

  return 0;
}
