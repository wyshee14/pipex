#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

// write into child, read from parent
// int main(void) 
// {
//     int    fd[2];
//     int    temp, term;
//     char *str = "Hello";
//     char buff[10];

//     temp = pipe(fd);
//     if (temp < 0)
//     {
//         perror("Pipe");
//         return (1);
//     }
//     temp = fork();
//     printf("Temp %d\n", temp);
//     if (temp < 0)
//     {
//         perror("Fork");
//         return (1);
//     }
//     else if (temp > 0)
//     {
//         printf("Parent\n");
//         close(fd[1]); // close write fd
//         // term = wait(NULL);
//         printf("Terminated %d\n", term);
//         read(fd[0], buff, 6);
//         printf("String read is %s\n", buff);
//         close(fd[0]);
//     }
//         else 
//     {
//         printf("Child\n");
//         close(fd[0]); // close read fd
//         write(fd[1], str, 6);
//         printf("String written is %s\n", str);
//         close(fd[1]);
//         //usleep(9999999);
//     }
//     if (term > 0)
//         printf("String is %s\n", buff);
//   return 0;
// }

int main()
{
int status;
pid_t pid1 = fork();
pid_t pid2 = fork();

if (pid1 == 0) {
    // Child 1
    printf("Child 1 (PID: %d)\n", getpid());
    exit(42);
} else if (pid2 == 0) {
    // Child 2
    printf("Child 2 (PID: %d)\n", getpid());
    exit(43);
} else {
    // Parent process
    pid_t child_pid = waitpid(pid1, &status, 0); // Wait for Child 1
    if (WIFEXITED(status)) {
        printf("Child 1 (PID: %d) exited with status: %d\n", child_pid, WEXITSTATUS(status));
    }

    child_pid = waitpid(pid2, &status, 0); // Wait for Child 2
    if (WIFEXITED(status)) {
        printf("Child 2 (PID: %d) exited with status: %d\n", child_pid, WEXITSTATUS(status));
    }
}
}