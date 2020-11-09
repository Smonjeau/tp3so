#include <stdio.h>
#include <unistd.h>

#include "utils.h"

#define PRIMER_ASCII_IMPRIMIBLE 32
#define ULTIMO_ASCII_IMPRIMIBLE 126 

void challenge1(){


    printf("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n"
    "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n"
    "Además tendrán que investigar otras preguntas para responder durante la defensa.\n"
    "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos.\n"
    "No basta con esperar la respuesta. Además, deberán implementar otro programa para comunicarse conmigo. Deberán estar atentos a los easter eggs.\n"
    "Ingresa \'entendido\' para pasar al siguiente desafío\n");

}
void challenge2(){

    printf("The Wire S1E5\n5295 888 6288\n");
}
void challenge3(){
    printf("https://ibb.co/tc0Hb6w\n");


}
void challenge4(){

    write(STDOUT_FILENO, "EBADF...\n\n", 10);
    write(1500, "La respuesta es fk3wfLCm3QvS\n\0\0\0", 32);
    perror("write");
}
void challenge5(){
    return;
}
void challenge6(){
    return;
}
void challenge7(){
    printf("Filter error\n");
    char * answer = "La respuesta es K5n2UFfpFMUN";
    int i=0;
    int size=0;
    while(answer[i]){
        int fd = randomChar(STDOUT_FILENO,STDERR_FILENO+5); //Menos probabilidad de que salga STDOUT
        if(fd==STDOUT_FILENO && answer[i]){
            write(fd,answer + i++,1);

        }
        else{
            char c;
            c = randomChar(PRIMER_ASCII_IMPRIMIBLE,ULTIMO_ASCII_IMPRIMIBLE);
            write(STDERR_FILENO,&c,1);
        }
    
    }
    return;
}
void challenge8(){
    return;
}
void challenge9(){
    return;
}
void challenge10(){
    return;
}
void challenge11(){
    return;
}
void challenge12(){
    return;
}