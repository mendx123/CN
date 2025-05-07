#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // For sleep function
#include <time.h>    // For random number generation

void sender();
void receiver(int frame);

int main() {
    srand(time(0));
    sender();
    return 0;
}

void sender() {
    int frame = 0;
    char ack;
    int timeout;
    while (frame < 3) {
        printf("Sender: Sending frame %d\n", frame);
        if (rand() % 10 < 3) {
            printf("Sender: Frame %d lost! Resending...\n\n", frame);
            sleep(1);
            continue;
        }
        receiver(frame);
        timeout = rand() % 10;
        printf("Sender: Waiting for acknowledgment...\n");
        sleep(1);
        
        if (timeout < 2) { 
            printf("Sender: Timeout occurred! Resending frame %d\n\n", frame);
            continue;
        }
        
        printf("Receiver: Enter 'y' to acknowledge frame %d: ", frame);
        scanf(" %c", &ack);
        
        if (ack == 'y' || ack == 'Y') {
            printf("Sender: Acknowledgment received for frame %d\n\n", frame);
            frame++; 
        } else {
            printf("Sender: Acknowledgment not received. Resending frame %d\n\n", frame);
        }
    }
}

void receiver(int frame) {
    printf("Receiver: Frame %d received successfully.\n", frame);
}
