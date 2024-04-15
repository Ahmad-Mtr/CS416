#include <stdio.h>

#include <sys/types.h>

#include <fcntl.h>

#include <unistd.h>

#include <stdlib.h>

#include <stdlib.h>

#include <stdlib.h>

#define Buff_size 20
char buff[Buff_size];
int countWords(int fd) {

  int c = 0;
  ssize_t n;
  lseek(fd, 0, SEEK_SET);

  while ((n = read(fd, buff, Buff_size)) > 0) {
    for (int i = 0; i < (int)n; i++) {
      if (buff[i] == " ") {
        c++;
      }
    }
  }
  printf("n: %d\n", n);
  if (n < 0) {
    printf("Error reading file");
    exit(1);
  }
  printf("BATATATATAA: %d\n", c);
  return c;
}

int isEmpty(int fd) {
  int len = lseek(fd, 0, SEEK_END);
  if (len) {
    printf("The file isn't Empty, Size: %d\n", len);
    return len;
  } else {
    printf("file is Empty\n");
    close(fd);
    return -1;
  }
}

int main() {

  int fd;
  fd = open("file1.txt", O_RDWR | O_CREAT, 0644);
  if (fd == -1) {
    printf("ERROR");
    exit(1);
  }
  int len = isEmpty(fd);

  countWords(fd);

  close(fd);
  return 0;
}
