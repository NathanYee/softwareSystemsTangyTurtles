// Reads in a specified song file and outputs to a specified serial port

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <stdlib.h>

// Open a file
//      filename: the name of the file to open
//      open_type: type of file open (read, write, etc.)
//      return: the FILE* of the specified song file
FILE* open_file(char *filename, char *open_type) {
    // Open file
    FILE *song = fopen(filename, open_type);

    // Error checking
    if (song == NULL) {
        fprintf(stderr, "open_file: Failed to open %s\n", filename);
        exit(-1);
    }
    else {
        fprintf(stdout, "open_file: Opened %s\n", filename);
    }

    return song;
}

// Open a serial port
//      port: the name of the serial port to open
//      return: the file descriptor of the specified serial port
int open_port(char *port) {
    int fd; // File descriptor for port
    speed_t baud = B9600; // Baud rate
    struct termios settings; // Struct to hold settings for serial port

    // Open the specified serial port with a few options:
    //     O_RDWR: open port for read and write
    //     O_NOCTTY: never allow port to become controlling terminal
    //     O_NDELAY: non-blocking / ignore DCD signal line
    fd = open(port, O_RDWR | O_NOCTTY | O_NDELAY);

    // Define serial port settings
    tcgetattr(fd, &settings);
    cfsetospeed(&settings, baud);

    // Apply serial port settings
    tcsetattr(fd, TCSANOW, &settings);
    tcflush(fd, TCOFLUSH);

    // Error checking
    if (fd == -1)
    {
        fprintf(stderr, "open_port: Unable to open %s\n", port);
        exit(-1);
    }
    else {
        fcntl(fd, F_SETFL, 0);
        fprintf(stdout, "open_port: Opened %s\n", port);
    }

    return fd;
}

// Write to a serial port
//      fd: file descriptor for serial port to write to
//      data: char array to write to the specified serial port
//      return: the number of bytes written to the serial port
int write_port(int fd, char *data) {
    // Find number of bytes to write
    int data_len = sizeof(data)-1;

    // Write to serial port
    int num_bytes_written = write(fd, data, data_len);

    // Error checking
    if (num_bytes_written < 0) {
        fprintf(stderr, "write_port: Failed to write \"%s\"\n", data);
        exit(-1);
    }
    else {
        fprintf(stdout, "write_port: Wrote \"%s\"\n", data);
    }

    return num_bytes_written;
}

// Write each line in a specified file to a specified serial port
int main(int argc, char *argv[]) {
    char ch;
    char *filename = "little_lamb.txt";
    char *port = "/dev/ttyUSB0";
    int frequency = 0;
    int duration = 0;

    // Read command line options
    while ((ch = getopt(argc, argv, "f:p:h")) != -1) {
        switch (ch) {
        case 'f':
            filename = optarg;
            break;
        case 'p':
             port = optarg;
            break;
        case 'h':
            fprintf(stdout, "Optargs:\n"
                            "   -f, define the song file name\n"
                            "   -p, define the serial port\n"
                            "   -h, help\n");
            return 0;
        }
    }

    // Increment through already parsed arguments
    argc -= optind;
    argv += optind;

    // Open song file
    FILE *song = open_file(filename, "r");
    
    // Open serial port
    int fd = open_port(port); // File descriptor for serial port

    // Write each line of the song file to the serial port
    while (fscanf(song, "%d, %d", &frequency, &duration) == 2) {
        char data[20];
        // sprintf(data, "%d, %d", frequency, duration);
        sprintf(data, "%d", frequency);
        write_port(fd, data);
        usleep(duration*1000);
    }

    // Close the serial port
    close(fd);

    return 0;
}
