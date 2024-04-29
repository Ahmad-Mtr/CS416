/*
In the main thread ask the user to enter radius of a circle, then create two
threads one calculates the area and print it. The other calculates the
circumference, print it. Then the main function should wait the threads to
finish and also print both area and Circumference returned by threads.

*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static float radius = 0;
float pie = 3.14;

void *func1(void *arg) {
  printf("*Inside thread 1********\n");
  float area = pie * radius * radius;

  printf("Area2: %f\n", area);
  printf("*****************1********\n");

  pthread_exit(NULL);
}

void *func2(void *arg) {
  printf("*Inside thread 2********\n");
  float circ = 2 * pie * radius;
  printf("Circ2: %f\n", circ);
  printf("*****************2********\n");

  pthread_exit(NULL);
}

int main() {
  pthread_t thr1, thr2;
  double area, circ;
  scanf("%f", &radius);
  pthread_create(&thr1, NULL, func1, (void *)thr1);
  pthread_create(&thr2, NULL, func2, (void *)thr2);

  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  // printf("Area: %f\nCirc: %f\n", area, circ);

  return 0;
}
}