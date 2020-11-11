#include "utils.h"
#include <stdio.h>

int randomInt(int a, int b){

    return a + rand() % (b-a+1);

}


double randomDouble(double a, double b){

    double num = a;

    while(num == a || num == b)
        num = a + rand() * (b-a)/RAND_MAX;
    
    return num;

}