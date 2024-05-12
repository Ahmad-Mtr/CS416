/*
1. Enhanced Multithreaded Circle Calculations with Mutex Synchronization:

Objective:

Modify the existing code to demonstrate thread synchronization using a mutex to ensure that only one thread accesses the shared variable radius at a time, preventing race conditions and incorrect calculations.
Implement error handling for user input to gracefully handle invalid radius values (e.g., negative numbers).
Enhance readability with clear comments and formatting.
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static float radius = 0;
float pie = 3.14;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Initialize mutex

void *func1(void *arg) {
  printf("*Inside thread 1********\n");

  pthread_mutex_lock(&mutex); // Acquire mutex lock

  if (radius <= 0) {
    printf("Error: Invalid radius. Please enter a positive value.\n");
    pthread_exit(NULL);
  }

  float area = pie * radius * radius;

  printf("Area2: %f\n", area);

  pthread_mutex_unlock(&mutex); // Release mutex lock

  printf("*****************1********\n");

  pthread_exit(NULL);
}

void *func2(void *arg) {
  printf("*Inside thread 2********\n");

  pthread_mutex_lock(&mutex); // Acquire mutex lock

  if (radius <= 0) {
    printf("Error: Invalid radius. Please enter a positive value.\n");
    pthread_exit(NULL);
  }

  float circ = 2 * pie * radius;

  printf("Circ2: %f\n", circ);

  pthread_mutex_unlock(&mutex); // Release mutex lock

  printf("*****************2********\n");

  pthread_exit(NULL);
}

int main() {
  pthread_t thr1, thr2;
  double area, circ;

  // Input validation loop for radius
  while (1) {
    printf("Enter radius of a circle: ");
    if (scanf("%f", &radius) != 1 || radius <= 0) {
      printf("Invalid input. Please enter a positive number.\n");
      // Clear the input buffer
      while (getchar() != '\n');
    } else {
      break;
    }
  }

  pthread_create(&thr1, NULL, func1, (void *)thr1);
  pthread_create(&thr2, NULL, func2, (void *)thr2);

  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);

  // No need to print area and circ here as threads already printed them
  // after proper synchronization

  return 0;
}
