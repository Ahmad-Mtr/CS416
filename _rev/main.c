#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    // Create an array to hold the command and its arguments
    char *args[] = {"git", "status", NULL};

    // Execute the git status command using execvp
    if (execvp("git", args) == -1) {
        perror("execvp failed");
        exit(EXIT_FAILURE);
    }

    // This code will only be reached if execvp fails
    printf("This line will not be executed\n");
    return 0;
}