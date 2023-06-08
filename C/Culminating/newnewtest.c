#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/io.h>

#define BASEPORT 0x378  // Parallel port base address

// 7-segment display patterns for digits 0 to 9
const unsigned char digitPatterns[] = {
    0x3F,  // 0
    0x06,  // 1
    0x5B,  // 2
    0x4F,  // 3
    0x66,  // 4
    0x6D,  // 5
    0x7D,  // 6
    0x07,  // 7
    0x7F,  // 8
    0x6F   // 9
};

void writeParallelPort(unsigned char data) {
    outb(data, BASEPORT);
}

void displayDigit(int digit, int display) {
    unsigned char pattern;

    if (digit < 0 || digit > 9)
        return;

    if (display == 0)
        pattern = digitPatterns[digit];
    else if (display == 1)
        pattern = digitPatterns[digit] << 4;
    else
        return;

    writeParallelPort(pattern);
}

int main() {
    if (ioperm(BASEPORT, 1, 1) != 0) {
        perror("Couldn't get permission to access the parallel port");
        exit(1);
    }

    // Example: Display "12" on the two 7-segment displays
    displayDigit(1, 0);
    displayDigit(2, 1);

    sleep(5);  // Wait for 5 seconds

    // Clear the displays
    displayDigit(0, 0);
    displayDigit(0, 1);

    // Release port permissions
    ioperm(BASEPORT, 1, 0);

    return 0;
}

