#include "utils.h"
#include <stdio.h>
#include <math.h>
#include <time.h>
char randomChar (int limite_inferior,int limite_superior){
    return limite_inferior + rand()%(limite_superior-limite_inferior+1);
}
double generateRandomFloat(){
    srand(time(0));
    double aux = cos(log(sqrt(randomChar(2,8))));
    char positive = randomChar(0,1);
    if(!positive)
        aux*=-1;
return aux;    
}
