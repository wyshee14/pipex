#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main() {
    int fd[2]; // File descriptors for the pipe
    pid_t cpid;
    char buf[1024];

    // Create a pipe
    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the process
    cpid = fork();
    if (cpid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (cpid == 0) { // Child process
        close(fd[1]); // Close unused write end
        read(fd[0], buf, sizeof(buf)); // Read from pipe
        printf("Child received: %s\n", buf);
        close(fd[0]); // Close read end after use
        exit(EXIT_SUCCESS);
    } else { // Parent process
        close(fd[0]); // Close unused read end
        const char *message = "Hello from parent!";
        write(fd[1], message, strlen(message) + 1); // Write to pipe
        close(fd[1]); // Close write end after sending
        wait(NULL); // Wait for child process to finish
        exit(EXIT_SUCCESS);
    }
}
