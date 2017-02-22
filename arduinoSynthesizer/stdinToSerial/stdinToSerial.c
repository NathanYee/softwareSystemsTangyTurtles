// Reads in a specified song file and outputs to a specified serial port

#include <stdio.h>      // standard input / output functions
#include <unistd.h>     // UNIX standard function definitions
#include <fcntl.h>      // File control definitions

#include <sys/stat.h>
#include <termios.h>
#include <string.h>
#include <stdlib.h>

FILE * open_file(char *filename, char *open_type) {
    // Open file
    FILE *song = fopen(filename, open_type);

    // Error checking
    if (song == NULL) {
        fprintf(stderr, "open_file: Failed to open %s\n", filename);
    }
    else {
        fprintf(stdout, "open_file: Opened %s\n", filename);
    }

    return song;
}

int open_port(char *port) {
    int fd; // File descriptor for port

    // Open the specified serial port with a few options:
    //     O_RDWR: open port for read and write
    //     O_NOCTTY: never allow port to become controlling terminal
    //     O_NDELAY: non-blocking / ignore DCD signal line
    fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);

    // Error checking
    if (fd == -1)
    {
        fprintf(stderr, "open_port: Unable to open %s\n", port);
    }
    else {
        fcntl(fd, F_SETFL, 0);
        fprintf(stdout, "open_port: Opened %s\n", port);
    }

    return fd;
}

int write_port(int fd, char *data) {
    // Find number of bytes to write
    int data_len = sizeof(data)-1;

    // Write to serial port
    int n = write(fd, data, data_len);

    // Error checking
    if (n < 0) {
        fprintf(stderr, "write_port: Write of %d bytes failed!\n", data_len);
        fprintf(stderr, "write_port: Error number %d!\n", n);
    }
    else {
        fprintf(stdout, "write_port: Wrote \n");
    }

    return n;
}

int main(int argc, char *argv[]) {
    char ch;
    char *filename = "little_lamb.txt";
    int frequency = 0;
    int duration = 0;
    char *port = "/dev/ttyUSB0";

    // Read command line options
    while ((ch = getopt(argc, argv, "f:p:")) != -1) {
        switch (ch) {
        case 'f':
            filename = optarg;
            break;
        case 'p':
             port = optarg;
            break;
        }
    }

    // Increment through already parsed arguments
    argc -= optind;
    argv += optind;

    // Open song file
    FILE *song = open_file(filename, "r");
    if (song  == NULL) {
        return -1;
    }
    
    // Open serial port
    int fd; // File descriptor for serial port
    if (fd = open_port(port) == -1) {
        return -1;
    }

    // Write each line of the song file to the serial port
    int n;
    while (fscanf(song, "%d, %d", &frequency, &duration) == 2) {
        char data[20];
        sprintf(data, "%d, %d", frequency, duration);
        if (n = write_port(fd, data) < 0) {
            return -1;
        }
    }
}
