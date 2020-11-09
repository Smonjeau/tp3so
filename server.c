
#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <sys/socket.h> 
#include <time.h>
#include <sys/types.h> 
#include "challenges.h"
#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 

void foo() __attribute__((section(".RUN_ME")));

void foo(){
    return;
}

 char * vaquita = 
 "_______________________\n"
"< ESTO ES UN EASTER_EGG >\n"
 "-----------------------\n"
        "     \\  ^__^\n"
         "     \\  (oo)\\_______\n"
            "        (__)\\       )\\/\\ \n"
                 "            ||----w |\n"
                 "            ||     ||";

char *answers[12] = {"entendido\n", "itba\n", "M4GFKZ289aku\n", "fk3wfLCm3QvS\n", "too_easy\n", ".RUN_ME\n",
		"K5n2UFfpFMUN\n", "BUmyYq5XxXGt\n", "u^v\n","chin_chu_lan_cha\n","gdb_rules\n","normal\n"};

  
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 

    int new=1;
    char buff[MAX]; 
    int n; 


    for (int challenge = 0;challenge <12;) { 
        bzero(buff, MAX); 
        if (new){
            printf("------------- DESAFIO -------------\n");
            new=0;
            (*challenges[11])();

        }
        
        // read the message from client and copy it in buffer 
        read(sockfd, buff, sizeof(buff)); 
        if(strcmp(buff,answers[challenge])== 0){
            challenge++;
            new=1;
            system("clear");

        }else{
            printf("Respuesta incorrecta: %s\n",buff);
            sleep(3);
            for(int i=0;i<strlen(buff);i++)
                putchar('\b');
        }

        
    } 
    printf("Felicitaciones, terminaste el desafío!\n");
} 
  
// Driver function 
int main() 

{ 
    srand(time(NULL));
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 
  
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        fprintf(stderr,"socket creation failed...\n"); 
        exit(0); 
    }
    // 
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
        fprintf(stderr,"setsockopt(SO_REUSEADDR) failed");    
   // else
       // printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        fprintf(stderr,"socket bind failed...\n"); 
        exit(0); 
    } 
  //  else
   //     printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
  //  else
   //     printf("Server listening..\n"); 
    len = sizeof(cli); 
  
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
   //else
  //      printf("server acccept the client...\n"); 
  
    // Function for chatting between client and server 
    func(connfd); 
  
    // After chatting close the socket 
    close(sockfd); 
} 
