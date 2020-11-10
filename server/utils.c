#include "utils.h"
#include <stdio.h>
#include <math.h>
#include <time.h>

int randomInt(int limite_inferior, int limite_superior){

    return limite_inferior + rand()%(limite_superior-limite_inferior+1);

}


double generateRandomFloat(){

    srand(time(0));

    double aux = cos(log(sqrt(randomInt(2, 8))));
    int positive = randomInt(0, 1);

    if(!positive)
        aux*=-1;

    return aux;

}