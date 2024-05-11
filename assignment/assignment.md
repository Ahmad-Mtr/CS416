# CS416: Systems Programming, Spring 2024

> Programming Assignment 1
> 
> Due Date: May 11, 11:59 PM

In lectures lecture 3 and 4 you have learned about process management using various system calls
(e.g., fork and wait) while in lectures 5 and 6, we have learned about file manipulation using multiple
system calls. In this excercise you need to write a program utilizing such system calls for the following
problem.
Assume that CS416 has three sections and the GJU eLearning system has generated the students‘
scores for an exam in three different files:
```
CS416_Section1_Midterm.txt
CS416_Section2_Midterm.txt
CS416_Section3_Midterm.txt
```
Assume that the file format is as follows (multiple lines and each line is a comma separated including
student name and student grade):
```
Abdullah Omar, 25
Ahmad Khaled, 26
Abbas Ali, 27
```

**Write a C program which uses the following psuedo code:**

1. The main program creates three parallel processes and each process reads one of the files.
Each process reads the corresponding file and creates the analysis summary in an output file
as follows:
    - The number of students enrolled in a section
    - The total of students‘ scores.
    
2. The main program reads the output data generates by each process and generates the final
output in a file to report the following:
    - The average of students scores in each section
    - The overall average of students scores

**Notes:**
1. For file management, you have to use **Only** the system calls which you learned in the class.
Otherwise, your assignment grade will be converted to zero immediately.

2. Your program should not assume there is a fixed number of rows in the section file. In
particular, your program should reads all data in a file until reaching to the end of a file.

**Submission Instructions:**

- The submission should include one directory which includes the related C program files (`*.c`,
`*.h`, and `*.txt`).
- Please compress the directory in a compressed file and name it in the following format:
```
programming_assign1_firstName_LastName.zip
```
