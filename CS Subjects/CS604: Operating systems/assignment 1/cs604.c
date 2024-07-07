#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int pipefd[2];  // file descriptor array for pipe
    pid_t child_pid;
    pid_t parent_pid = getpid();   // process id

    if (pipe(pipefd) == -1) {  // create pipe, check for errors
        perror("Pipe creation failed");
        return 1;
    }

    child_pid = fork();  // create child process

    if (child_pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {  // Child process
        pid_t child_process_id = getpid();
        close(pipefd[0]); // Close unused read end of the pipe
        write(pipefd[1], &child_process_id, sizeof(child_process_id)); // Write child process ID to pipe
        close(pipefd[1]); // Close the write end of pipe
        return 0;
    } else {  // Parent process
        pid_t child_process_id;
        close(pipefd[1]); // Close unused write end of pipe
        read(pipefd[0], &child_process_id, sizeof(child_process_id)); // Read child process ID from pipe
        close(pipefd[0]); // Close the read end of pipe
      
        printf("parent (pid:%d): Received child process ID %d\n", parent_pid, child_process_id);
        printf("parent (pid:%d): Parent process ID is %d\n", parent_pid, parent_pid);
  
    return 0;
    }
}
