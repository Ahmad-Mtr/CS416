/*
There are 15 seats available for the movie.
- The user can book the seat, via three machines (machine 0, machine 1, and
machine 2).
- No customer details needed for the reservation.
- After booking is done, the system shows the machine used and, the number of
remaining seat
*/
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define THREAD_NUM 3

int numOfSeats = 15;
sem_t semaphore;

void *routine(void *args) {
  sem_wait(&semaphore);
  while(1) { 
  sleep(1);
  if (numOfSeats > 0) {
    numOfSeats--;
    printf("Machine %d booked a seat. Remaining seats: %d\n", *(int *)args+1,
           numOfSeats);

    sem_post(&semaphore);
    
    free(args);
  }else{
    printf("Machine %d tried to book a seat. but no Seats are available\n", *(int *)args+1);
    sem_post(&semaphore);
    
    free(args);
  } 
    if (numOfSeats == 0) break;
  }
}

int main(int argc, char *argv[]) {
  pthread_t th[THREAD_NUM];
  sem_init(&semaphore, 0, 3);
  int i;

  for (i = 0; i < THREAD_NUM; i++) {
    int *a = malloc(sizeof(int));
    *a = i;
    if (pthread_create(&th[i], NULL, &routine, a) != 0) {
      printf("Failed to create thread");
    }
  }
  for (i = 0; i < THREAD_NUM; i++) {
    if (pthread_join(th[i], NULL) != 0) {
      printf("Failed to join thread");
    }
  }
  sem_destroy(&semaphore);
  return 0;
}
