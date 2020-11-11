#include "utils.h"

int randomInt(int limite_inferior, int limite_superior){

    return limite_inferior + rand()%(limite_superior-limite_inferior+1);

}