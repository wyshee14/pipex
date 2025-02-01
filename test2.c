#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// write into child, read from parent
int main(void) 
{
    int    fd[2];
    int    temp, term;
    char *str = "Hello";
    char buff[10];

    temp = pipe(fd);
    if (temp < 0)
    {
        perror("Pipe");
        return (1);
    }
    temp = fork();
    printf("Temp %d\n", temp);
    if (temp < 0)
    {
        perror("Fork");
        return (1);
    }
    else if (temp > 0)
    {
        printf("Parent\n");
        close(fd[1]); // close write fd
        // term = wait(NULL);
        printf("Terminated %d\n", term);
        read(fd[0], buff, 6);
        printf("String read is %s\n", buff);
        close(fd[0]);
    }
        else 
    {
        printf("Child\n");
        close(fd[0]); // close read fd
        write(fd[1], str, 6);
        printf("String written is %s\n", str);
        close(fd[1]);
        //usleep(9999999);
    }
    if (term > 0)
        printf("String is %s\n", buff);
  return 0;
}