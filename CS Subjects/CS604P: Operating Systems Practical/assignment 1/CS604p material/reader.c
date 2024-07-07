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
    char message[100];
    
    fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("Error while opening the FIFO");
        exit(EXIT_FAILURE);
    }

    read(fd, message, sizeof(message));
    printf("Reader process recieved message: %s\n", message);

    close(fd);
    return 0;
}
