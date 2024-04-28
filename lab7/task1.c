/*
  For the First time I'm adding proper error handling 💪
*/
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

  int numOfStudents = 0;
  printf("num: ");
  scanf("%d", &numOfStudents);
  float *mallocArr = malloc(numOfStudents * sizeof(float));
  int i = 0;

  for (i = 0; i < numOfStudents; i++) {
    printf("Student[%d]: ", i + 1);

    // ![0, 100] ErRoR hAnDlInG
    do {
      scanf("%f", &mallocArr[i]);
      if (mallocArr[i] < 0 || mallocArr[i] > 100) {
        printf("Error: Invalid Input, re-enter:\nStudent[%d]: ", i + 1);
      }
    } while (mallocArr[i] > 100.0 || mallocArr[i] < 0.0);
    printf("\n");
  }

  mallocArr = realloc(mallocArr, (numOfStudents + 3) * sizeof(float));
  mallocArr[i] = 90;
  mallocArr[i + 1] = 85;
  mallocArr[i + 2] = 88;

  // for calculating Avg, max
  numOfStudents += 3;
  float sum = 0;
  float max = mallocArr[0];
  ;

  printf("\n**********************\n");
  for (int i = 0; i < numOfStudents; i++) {
    sum += mallocArr[i];
    if (mallocArr[i] > max)
      max = mallocArr[i];
    printf("Student[%d]: %.2f\n", i + 1, mallocArr[i]);
  }
  printf("**********************\nAvarage: %0.2f\nMax: %0.2f\n",
         sum / numOfStudents, max);
  return 0;
}
