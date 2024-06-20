// #include "assignment2.h"
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define CHUNK_SIZE 1024
#define BUFFER_SIZE 1024
#define SECTION_COUNT 3

typedef struct {
  int totalStudents;
  int totalMarks;
} SectionSummary;

SectionSummary *summaries;
pthread_mutex_t mutex;

void *analyzeSection(void *arg) {
  char i = *((char *)arg);
  free(arg);
  char c[2] = {i, '\0'};
  int section = atof(c);
  // open files
  // prepeare msgs
  // read data
  // write result

  char *input = (char *)malloc(sizeof("CS416_section1_midterm.txt"));
  char *output = (char *)malloc(sizeof("section1_data.txt"));

  sprintf(input, "CS416_section%c_midterm.txt", i);
  sprintf(output, "section%c_data.txt", i);

  int fdIn = open(input, O_RDONLY, 0644);
  int fdOut = open(output, O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (fdIn == -1) {
    perror("@fdIn: Error opening file\n");
    pthread_exit(NULL);
  }

  int totalStudents = 0;
  int totalMarks = 0;

  char buffer[CHUNK_SIZE];
  size_t bytesRead;
  int j;
  while ((bytesRead = read(fdIn, &buffer, CHUNK_SIZE)) > 0) {
    for (j = 0; j < bytesRead; j++) {
      if (buffer[j] ==
          '\n') { // meainging Line's End, so previous 2 chars are the mark.
        char a = buffer[j - 2];
        char b = buffer[j - 1];

        char c[3]; // 3 chars for `\0`
        sprintf(c, "%c%c", a, b);

        int mark = atof(c); // typecasting
        totalMarks += mark;
        totalStudents++;
      } else if (buffer[j + 1] == '\0') { // case End of File
        char a = buffer[j - 1];
        char b = buffer[j];

        char c[3]; // 3 chars for `\0`
        sprintf(c, "%c%c", a, b);

        int mark = atof(c); // typecasting
        totalMarks += mark;
        totalStudents++;
      }
    }
  }
  char summary[CHUNK_SIZE];
  sprintf(summary,
          "Number of students enrolled in this section: %d\nTotal score of "
          "students: %d\n",
          totalStudents, totalMarks);

  write(fdOut, summary, strlen(summary));

  close(fdIn);
  close(fdOut);

  pthread_mutex_lock(&mutex);
  summaries[section-1].totalStudents = totalStudents;
  summaries[section-1].totalMarks = totalMarks;
  pthread_mutex_unlock(&mutex);

  pthread_exit(NULL);
}

float getAvg(int totalStudents, int totalScore) {
  if (totalStudents == 0)
    return 0;
  return (float)totalScore / totalStudents;
}

void calculateReport() {
  int totalStudentsAllSections = 0;
  int totalMarksAllSections = 0;
  float avgSection[SECTION_COUNT];

  for (int i = 0; i < SECTION_COUNT; i++) {
    totalStudentsAllSections += summaries[i].totalStudents;
    totalMarksAllSections += summaries[i].totalMarks;
    avgSection[i] = getAvg(summaries[i].totalStudents, summaries[i].totalMarks);
  }

  float overallAvg = getAvg(totalStudentsAllSections, totalMarksAllSections);

  int fdOut = open("final_report.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fdOut == -1) {
    perror("@fdOut: Error opening file\n");
    exit(1);
  }

  char finalReport[BUFFER_SIZE];
  int offset = 0;
  offset += sprintf(finalReport + offset,
                    "Average score of students in each section:\n");
  for (int i = 0; i < SECTION_COUNT; i++) {
    offset += sprintf(finalReport + offset, "Section %d: %.2f\n", i + 1,
                      avgSection[i]);
  }
  offset +=
      sprintf(finalReport + offset, "Overall average: %.2f\n", overallAvg);

  write(fdOut, finalReport, strlen(finalReport));
  close(fdOut);
}

int main() {
  pthread_t threads[SECTION_COUNT];
  summaries = (SectionSummary *)malloc(SECTION_COUNT * sizeof(SectionSummary));
  pthread_mutex_init(&mutex, NULL);

  for (int i = 0; i < SECTION_COUNT; i++) {
    char *section = (char *)malloc(sizeof(char));
    char processName = '1' + i;
    *section = processName;

    if (pthread_create(&threads[i], NULL, analyzeSection, section) != 0) {
      perror("@pthread_create: Error creating thread\n");
      exit(1);
    }
  }

  for (int i = 0; i < SECTION_COUNT; i++) {
    pthread_join(threads[i], NULL);
  }

  calculateReport();

  pthread_mutex_destroy(&mutex);
  free(summaries);

  return 0;
}
