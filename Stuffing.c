#include <stdio.h>
#include <string.h>

int main() {
    char data[100], stuffed[200];
    int i, j = 0;
    char FLAG = '@',End='#', ESC = '/';

    printf("Enter data: ");
    scanf("%s", data);

    stuffed[j++] = FLAG;

    for (i = 0; i < strlen(data); i++) {
        if (data[i] == FLAG || data[i] == ESC || data[i] == End) {
            stuffed[j++] = ESC;
        }
        stuffed[j++] = data[i];
    }

    stuffed[j++] = End;
    stuffed[j] = '\0';

    printf("Stuffed Data: %s\n", stuffed);
}
