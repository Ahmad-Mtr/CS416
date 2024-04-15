#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  int numOfStudents = 0;
  printf("num: ");
  scanf("%d", &numOfStudents);
  double *mallocArr = malloc(numOfStudents * sizeof(double));
  int i;
  for (i = 0; i < numOfStudents; i++) {
    printf("Student[ %d ]: ", i + 1);
    int x;
    scanf("%f", &x);
    mallocArr[i] = x;
    printf("\n");
  }
  mallocArr = realloc(mallocArr, (numOfStudents + 3) * sizeof(double));
  mallocArr[i] = 90;
  mallocArr[i + 1] = 85;
  mallocArr[i + 2] = 88;

  for (int i = 0; i < numOfStudents + 3; i++) {
    printf("Student[ %d ]: %d\n", i + 1, mallocArr[i]);
  }
  return 0;
}
