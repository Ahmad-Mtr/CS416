#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define CHUNK_SIZE 1024
#define BUFFER_SIZE 1024
#define PROCESS_COUNT 3

void analayzeSection(char i) {
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
    perror("@fdIn: Error opening File\n");
    exit(1);
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
}
float getAvg(int totalStudents, int totalScore) {
  if (totalStudents == 0) // dividing by zero destroys execution :)
    return 0;
  else
    return (float)totalScore / totalStudents;
}
void calculateReport() {
  // get data
  // calculate avg foreach
  // write to file

  int totalStudents[PROCESS_COUNT];
  int totalMarks[PROCESS_COUNT];
  float avgSection[PROCESS_COUNT];

  int totalStudentsAllSections = 0;
  int totalMarksAllSections = 0;
  float overAllAvg = 0;
  for (int i = 0; i < PROCESS_COUNT; i++) {
    char input[BUFFER_SIZE];
    sprintf(input, "section%d_data.txt", i + 1);
    int fd = open(input, O_RDONLY, 0644);
    if (fd == -1) {
      perror("@fd: Error opening File\n");
      exit(1);
    }
    char buffer[BUFFER_SIZE];

    size_t bytesRead;
    if (read(fd, &buffer, BUFFER_SIZE) > 0) {
      if (sscanf(buffer,
                 "Number of students enrolled in this section: %d\nTotal score "
                 "of students: %d\n",
                 &totalStudents[i], &totalMarks[i]) == 2) {
        totalStudentsAllSections += totalStudents[i];
        totalMarksAllSections += totalMarks[i];
      }
    }
    close(fd);
  }
  for (int i = 0; i < PROCESS_COUNT; i++) {
    avgSection[i] = getAvg(totalStudents[i], totalMarks[i]);
  }
  overAllAvg = getAvg(totalStudentsAllSections, totalMarksAllSections);

  int fdOut = open("final_report.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (fdOut == -1) {
    perror("@fdOut: Error opening File\n");
    exit(1);
  }
  char *finalReport = (char *)malloc(BUFFER_SIZE);

  int offset = 0;

  // Construct the formatted string procedurally using a loop
  offset += sprintf(finalReport + offset,
                    "Average score of students in each section:\n");
  for (int i = 0; i < PROCESS_COUNT; i++) {
    offset += sprintf(finalReport + offset, "Section %d: %0.2f\n", i + 1,
                      avgSection[i]);
  }
  offset +=
      sprintf(finalReport + offset, "Overall average: %0.2f\n", overAllAvg);

  // sprintf(finalReport,
  //         "Average score of students in each section:\nSection 1: "
  //         "%0.2f\nSection 2: %0.2f\nSection 3: %0.2f\nOverall average:
  //         %0.2f\n", avgSection[0], avgSection[1], avgSection[2], overAllAvg);

  write(fdOut, finalReport, strlen(finalReport));

  close(fdOut);
}
int main() {
  pid_t pid;

  for (int i = 0; i < PROCESS_COUNT; i++) {
    pid = fork();
    if (pid < 0) {
      perror("@pid: Error forking\n");
      exit(1);
    } else if (pid == 0) {
      char processName = '1';
      analayzeSection(processName + i);
      exit(0);
    }
  }

  // I was looking for an easier way to wait for all the children to finish
  // wihout tracking pids , I've found this online
  for (int i = 0; i < PROCESS_COUNT; i++) {
    wait(NULL);
  }

  calculateReport();
  return 0;
}