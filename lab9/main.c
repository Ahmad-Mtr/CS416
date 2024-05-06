/*
Write a program that create three additional threads alongside the main thread.
Each thread is responsible to open the file and, determine its size, and append
a unique sentence indicating the thread's identity (e.g., 'accessed by thread 1'
for the first thread) at the end of the file. Ensure that each thread waits for
the others to complete before proceeding, and print a sentence at the end of the
main indicating that all threads are done.
*/
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int fd;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *func1(void *arg) {
  printf("*Inside thread 1********\n");

  pthread_mutex_lock(&mutex);

  fd = open("file1.txt", O_RDWR | O_CREAT, 0644);

  int off = lseek(fd, 0, SEEK_END);
  printf("off 1: %d\n", off);

  const char *msg = "Accessed by Thread1\n";
  printf("%s", msg);
  write(fd, msg, strlen(msg));

  close(fd);

  pthread_mutex_unlock(&mutex);

  printf("*****************1********\n");

  pthread_exit(NULL);
}
void *func2(void *arg) {
  printf("*Inside thread 2********\n");

  pthread_mutex_lock(&mutex);

  fd = open("file1.txt", O_RDWR | O_CREAT, 0644);

  int off = lseek(fd, 0, SEEK_END);
  printf("off 2: %d\n", off);

  const char *msg = "Accessed by Thread2\n";
  printf("%s", msg);
  write(fd, msg, strlen(msg));

  close(fd);

  pthread_mutex_unlock(&mutex);

  printf("*****************2********\n");

  pthread_exit(NULL);
}

void *func3(void *arg) {
  printf("*Inside thread 3********\n");

  pthread_mutex_lock(&mutex);

  fd = open("file1.txt", O_RDWR | O_CREAT, 0644);

  const char *msg = "Accessed by Thread3\n";

  int off = lseek(fd, 0, SEEK_END);
  printf("off 3: %d\n", off);

  write(fd, msg, strlen(msg));

  close(fd);

  pthread_mutex_unlock(&mutex);

  printf("*****************3********\n");

  pthread_exit(NULL);
}
int main() {
  pthread_mutex_init(&mutex, NULL);
  pthread_t thr1, thr2, thr3;

  pthread_create(&thr1, NULL, func1, NULL);
  pthread_create(&thr2, NULL, func2, NULL);
  pthread_create(&thr3, NULL, func3, NULL);

  pthread_join(thr1, NULL);
  pthread_join(thr2, NULL);
  pthread_join(thr3, NULL);

  pthread_mutex_destroy(&mutex);

  printf("All threads are done\n");
  return 0;
}
