#include <stdio.h>
#include <unistd.h>
#include <parport.h>

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

void displayDigit(int digit, int display, struct parport *port) {
    unsigned char pattern;

    if (digit < 0 || digit > 9)
        return;

    if (display == 0)
        pattern = digitPatterns[digit];
    else if (display == 1)
        pattern = digitPatterns[digit] << 4;
    else
        return;

    parport_data_out(port, pattern);
}

int main() {
    struct parport *port;

    // Open the parallel port
    port = parport_open(BASEPORT, PARPORT_DEV_EXCL);

    if (port == NULL) {
        perror("Failed to open the parallel port");
        return 1;
    }

    // Example: Display "12" on the two 7-segment displays
    displayDigit(1, 0, port);
    displayDigit(2, 1, port);

    sleep(5);  // Wait for 5 seconds

    // Clear the displays
    displayDigit(0, 0, port);
    displayDigit(0, 1, port);

    // Close the parallel port
    parport_close(port);

    return 0;
}

