/*
2. Producer-Consumer Problem with Semaphore Synchronization:

Objective:

Implement a producer-consumer scenario using semaphores for coordination.
The producer thread will generate items (e.g., integers or strings) and add them to a shared buffer.
The consumer thread will retrieve items from the buffer and process them (e.g., print or store).
Semaphores will be used to control access to the buffer, ensuring data integrity and preventing buffer overflow/underflow.
*/
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5 // Define the buffer size

int buffer[BUFFER_SIZE];
int in = 0, out = 0; // Indexes for producer and consumer

sem_t empty; // Semaphore for empty slots in the buffer
sem_t full;  // Semaphore for filled slots in the buffer

void *producer(void *arg) {
  while (1) {
    int item = rand() % 100; // Generate a random item (integer)

    sem_wait(&empty); // Wait if the buffer is full

    buffer[in] = item;
    in = (in + 1) % BUFFER_SIZE; // Update producer index (circular buffer)

    printf("Producer produced: %d\n", item);

    sem_post(&full); // Signal that a new item is added

    sleep(1); // Simulate production time (optional)
  }
}

void *consumer(void *arg) {
  while (1) {
    sem_wait(&full); // Wait if the buffer is empty

    int item = buffer[out];
    out = (out + 1) % BUFFER_SIZE; // Update consumer index (circular buffer)

    printf("Consumer consumed: %d\n", item);

    sem_post(&empty); // Signal that a slot is empty

    sleep(2); // Simulate consumption time (optional)
  }
}

int main() {
  sem_init(&empty, 0, BUFFER_SIZE); // Initialize empty semaphore to buffer size
  sem_init(&full, 0, 0);          // Initialize full semaphore to 0 (initially empty)

  pthread_t prod, cons;

  pthread_create(&prod, NULL, producer, NULL);
  pthread_create(&cons, NULL, consumer, NULL);

  pthread_join(prod, NULL);
  pthread_join(cons, NULL);

  sem_destroy(&empty);
  sem_destroy(&full);

  return 0;
}
