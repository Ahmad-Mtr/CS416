#ifndef ASSIGNMENT2_H
#define ASSIGNMENT2_H

#include <pthread.h>

#define CHUNK_SIZE 1024
#define BUFFER_SIZE 1024
#define SECTION_COUNT 3

typedef struct {
    int totalStudents;
    int totalMarks;
} SectionSummary;

void* analyzeSection(void* arg);
float getAvg(int totalStudents, int totalScore);
void calculateReport();

#endif
