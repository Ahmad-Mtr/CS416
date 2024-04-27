/*
Given the file file1.txt, write a C program that accomplishes the following
tasks:
  - Open the file file1.txt.
  - Make a function that check whether the file is Empty or not. If the file is
Empty, print a message “The File was Empty Before accessing” in terminal and in
the file then close the file. If the file is not empty print the size in bytes
in the terminal.
  - Make a function to count number of words [by searching for spaces and count
them +1]. But read the file as chunks. Then print the number of words in
terminal.
  - Extra: Make a function that search for the word computer (with any capital
or small case) and replace it with the word COMPUTER. And then print on terminal
number of replaced words.
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define Buff_size 20
char buff[Buff_size];
int countWords(int fd) {

  int c = 0;
  ssize_t n;
  lseek(fd, 0, SEEK_SET);

  while ((n = read(fd, buff, Buff_size)) > 0) {
    for (int i = 0; i < (int)n; i++) {
      if (buff[i] == ' ' || buff[i] == '\n' || buff[i] == '\t') {
        c++;
      }
    }
  }

  printf("BATATATATAA: %d\n", c + 1);
  return c + 1;
}

int isEmpty(int fd) {
  off_t len = lseek(fd, 0, SEEK_END);
  if (len) {
    printf("file isn't Empty, size: %ld\n", (long)len);
    close(fd);
    return -1;
  } else {
    const char *msg = "The File was Empty Before accessing\n";
    printf("%s", msg);
    write(fd, msg, strlen(msg));
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
