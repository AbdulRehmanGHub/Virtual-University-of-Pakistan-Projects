/* Name: Abdul Rehman
   VU-ID: BC220424444	*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#define FIFO_PATH "/tmp/myfifo"

int main() {
    int fd;
    char message[50] = "Hello from writer program!";
    mkfifo(FIFO_PATH, 0666);
    
    fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Error while opening the FIFO");
        exit(EXIT_FAILURE);
    }
    write(fd, message, sizeof(message));
    printf("writer process sending message : %s\n", message);
    close(fd);
    
    return 0;
}
