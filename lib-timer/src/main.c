#include <evaluation.h>

#include <stdlib.h>
#include <stdio.h>

int main() {

    startTimer();

    startExecutionTime();

    unsigned int random1 = generatePseudoRandomNumber();
    unsigned int random2 = generatePseudoRandomNumber();
    unsigned int random3 = generatePseudoRandomNumber();

    if (random1 != random2) {

        printf("El primer numero: %u, es distinto al segundo: %u\n", random1, random2);

    }

    if (random2 != random3) {

        printf("El segundo numero: %u, es distinto al tercero: %u\n", random2, random3);

    }

    if (random1 != random3) {

        printf("El primer numero: %u, es distinto al tercero: %u\n", random1, random3);

    }
    
    unsigned int time = stopExecutionTime();

    printf("El tiempo de ejecucion fue %u\n", time);

    stopTimer();

    return 0;

}
