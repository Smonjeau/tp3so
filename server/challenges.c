#include <stdio.h>
#include <unistd.h>
#include <math.h>

#include "utils.h"

#define PRIMER_ASCII_IMPRIMIBLE 32
#define ULTIMO_ASCII_IMPRIMIBLE 126 

// ------------------------------------------ DATA HIDDEN ON BINARY -------------------------------------------

char * izipizi = "too_easy\n";

void foo() __attribute__((section(".RUN_ME")));

void foo(){ return; }

char * vaquita = 
 "_______________________\n"
"< ESTO ES UN EASTER_EGG >\n"
 "-----------------------\n"
        "     \\  ^__^\n"
         "     \\  (oo)\\_______\n"
            "        (__)\\       )\\/\\ \n"
                 "            ||----w |\n"
                 "            ||     ||";


// ------------------------------------------ CHALLENGES -------------------------------------------


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

    printf("respuesta = strings:36\n");

}


void challenge6(){

    printf(".plt .plt_got .text ? .fini .rodata .eh_frame_hdr\n");

}


void challenge7(){

    printf("Filter error\n");

    char * answer = "La respuesta es K5n2UFfpFMUN";
    int i=0;
    int size=0;

    while(answer[i]){
        int fd = randomInt(STDOUT_FILENO, STDERR_FILENO+5); //Menos probabilidad de que salga STDOUT

        if(fd==STDOUT_FILENO && answer[i]){
            write(STDOUT_FILENO, answer + i++, 1);
        }else{
            char c = (char) randomInt(PRIMER_ASCII_IMPRIMIBLE, ULTIMO_ASCII_IMPRIMIBLE);
            write(STDERR_FILENO, &c, 1);
        }
    }

}


void challenge8(){
   
   printf("¿?\n");

   printf("\x1B[30;40m La respuesta es BUmyYq5XxXGt \x1B[0m\n");
   
}


void challenge9(){
    
    printf("Latexme\n");
    printf("Si\n");
    printf(" \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\\frac{u'}{u})\n");
    printf("Entonces\n");
    printf(" y = \n");
    
}


void challenge10(){
    
    printf("quine\n");

    if(system("gcc quine.c -o quine") == 0){

        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");

        system("./quine > out");

        if(system("diff quine.c out") == 0){
            printf("La respuesta es chin_chu_lan_cha\n");
        }else{
            printf("diff encontró diferencias.\n");
        }

    }

    system("rm out quine");
    
}


int value(){
    return 0;
}

int gdbme(){

    if(value() == 0x12345678){
        printf("La respuesta es gdb_rules\n");
        return 0;
    }

}

void challenge11(){
    
    printf("gdbme y encontrá el valor mágico\n");

    gdbme();
    
}


void challenge12(){

    printf("Me conocés\n");

    for(int i=0; i<900; i++){
        double num = cos(log(sqrt(randomInt(2, 8))));
        int positive = randomInt(0, 1);

        if(!positive)
            num *= -1;

        printf("%g ", num);
    }

    printf("\n");

}