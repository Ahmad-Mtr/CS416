#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 25
int main() {
  pid_t pid;
  int f1, f2;
  off_t _offset;
  ssize_t numByteRead, numByteWritten;
  char buffer[BUF_SIZE];
  const char *name = "Ahmad MAhmoud";
  const char *course = "Systems Programming";
  pid = fork();
  if (pid < 0) {
    // Error
  } else if (pid == 0) {
    f1 = open("Name.txt", O_RDWR | O_CREAT,
              0644); // open   or create the first file
    if (f1 == -1) {
      printf("Error opening or creating file1");
      exit(1);
    }
    numByteWritten = write(f1, course, strlen(course));

  } else {
    // Parent
    wait(NULL);

    _offset = lseek(f1, 100, SEEK_END);
    write(f1, name, strlen(name));
    close(f1);
  }

  return 0;
}
