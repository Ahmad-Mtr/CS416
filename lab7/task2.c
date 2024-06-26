/*
  Task 2:
  Write a program that do the following:
  1. Create a file called (MyInfo.txt).
  2. Write on the file your full name, given that name is dynamic allocated.
  3. Resize the already allocated memory to hold the full name and your major.
  4. Rewrite the new information to the file.
  5. Make sure to free the dynamic allocated, and close open files
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *n = malloc(50);
  if (n == NULL) {
    printf("Error: @malloc\n");
    return 1;
  }

  strcpy(n, "Ahmad Mahmoud\n");

  int fd = open("myinfo.txt", O_RDWR | O_TRUNC, 0644);
  if (fd == -1) {
    printf("Error: open failed\n");
    free(n);
    return 1;
  }

  write(fd, n, strlen(n));

  n = realloc(n, strlen(n) + strlen("Computer Science") + 1);
  if (n == NULL) {
    printf("Error: realloc failed\n");
    close(fd);
    return 1;
  }

  strcat(n, "Computer Science");
  lseek(fd, 0, SEEK_SET);
  write(fd, n, strlen(n));

  close(fd);
  free(n);

  return 0;
}