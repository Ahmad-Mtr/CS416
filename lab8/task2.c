/*
In the main, create a static array with size entered by user. Also, in the main
thread enter the values of the array. Later create number of threads equal to
the size of the array, and each thread should call a square function that square
the value.
*/
#include <pthread.h>
#include <stdio.h>

static int k = 0;

void *sqr(void *arg) {
  long int s = (long int)arg;
  s *=  s;
  return (void *)s;
}
int main() {
  int n = 0;
  printf("N: \n");
  scanf("%d", &n);
  int arr[n];

  for (int i = 0; i < n; i++) {
    printf("i: ");
    scanf("%d", &arr[i]);
    printf("\n");
  }

  pthread_t threads[n];
  for (int i = 0; i < n; i++) {
    pthread_create(&threads[i], NULL, sqr, (void *)arr[i]);
  }
  for (int i = 0; i < n; i++) {
    pthread_join(threads[i], (void **)&arr[i]);
  }

  printf("****************************\n");
  for (int i = 0; i < n; i++) {
    printf("%d \n", (int)arr[i]);
  }
  return 0;
}