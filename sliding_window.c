#include <stdio.h>

int main() {
    int totalFrames, windowSize;
    int ack[50] = {0}; 
    printf("Enter total number of frames: ");
    scanf("%d", &totalFrames);

    printf("Enter window size: ");
    scanf("%d", &windowSize);

    int i = 0;
    while (i < totalFrames) {
        printf("\nSending frames: ");
        for (int j = i; j < i + windowSize && j < totalFrames; j++) {
            printf("%d ", j);
        }

        printf("\nEnter acknowledgements for these frames (1 = ACK, 0 = NACK):\n");

        for (int j = i; j < i + windowSize && j < totalFrames; j++) {
            printf("Frame %d: ", j);
            scanf("%d", &ack[j]);
        }

        for (int j = i; j < i + windowSize && j < totalFrames; j++) {
            if (ack[j] == 0) {
                printf("Retransmitting frame %d\n", j);
                ack[j] = 1; 
        }

        i += windowSize;
    }

    printf("\nAll frames sent successfully using Selective Repeat ARQ.\n");

    return 0;
}
