#include <config.h>

#include <stdio.h>
#include <stdlib.h>

#define LFSRCYCLES 3

unsigned int lfsrAlgorithm(unsigned int seed);

unsigned int executionTime = 0;

int startTimer() {

    FILE *fd = fopen("/dev/timer", "wb");

    if (fd == NULL) {

        printf("Error starting the timer\n");
        exit(1);

    }

    fwrite("1", 1, 1, fd);
    fclose(fd);

    return 0;

}

int stopTimer() {

    FILE *fd = fopen("/dev/timer", "wb");

    if (fd == NULL) {

        printf("Error stopping the timer\n");
        exit(1);

    }

    fwrite("0", 1, 1, fd);
    fclose(fd);

    return 0;

}

unsigned int readTimer() {

    char readValue[8];

    FILE *fd = fopen("/dev/timer", "rb");

    if (fd == NULL) {

        printf("Error reading the timer\n");
        exit(1);

    }

    fread(readValue, sizeof(readValue), 1, fd);
    fclose(fd);

    return (unsigned int) strtol(readValue, NULL, 16);

}

int startExecutionTime() {

    executionTime = readTimer();

    return 0;

}

unsigned int stopExecutionTime() {

    return readTimer() - executionTime;

}

unsigned int generatePseudoRandomNumber() {

    unsigned int seed = readTimer();

    for (int i = 0; i < LFSRCYCLES; i++) {

        seed = lfsrAlgorithm(seed);

    }

    return seed;

}

unsigned int lfsrAlgorithm(unsigned int seed) {

    unsigned int firstBit = 1 & seed;
    unsigned int secondBit = 1 & (seed >> 2);
    unsigned int thirdBit = 1 & (seed >> 3);
    unsigned int fourthBit = 1 & (seed >> 5);

    unsigned int resultBit = (((firstBit ^ secondBit) ^ thirdBit) ^ fourthBit) << 31;

    return (seed >> 1) | resultBit;

}
