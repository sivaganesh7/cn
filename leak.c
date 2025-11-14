#include <stdio.h>

int main() {
    int bucket, leak, in, stored = 0;

    printf("Bucket size: ");
    scanf("%d", &bucket);

    printf("Leak rate: ");
    scanf("%d", &leak);

    while (1) {
        printf("\nIncoming packets (-1 to stop): ");
        scanf("%d", &in);

        if (in == -1) break;

        // Check overflow
        if (stored + in > bucket) {
            printf("Dropped: %d\n", (stored + in) - bucket);
            stored = bucket;
        } else {
            stored += in;
        }

        // Leak packets
        stored = (stored < leak) ? 0 : stored - leak;

        printf("Stored after leak: %d\n", stored);
    }
    return 0;
}
