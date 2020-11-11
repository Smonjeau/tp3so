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



char *answers[12] = {"entendido\n", "itba\n", "M4GFKZ289aku\n", "fk3wfLCm3QvS\n", "too_easy\n", ".RUN_ME\n",
		"K5n2UFfpFMUN\n", "BUmyYq5XxXGt\n", "u^v\n", "chin_chu_lan_cha\n", "gdb_rules\n", "normal\n"};

  
void chat(int sockfd){ 

    int new=1;
    char buff[MAX];

    for (int challenge = 0; challenge < 12; challenge++) {

        int retry = 1;
        while(retry){

            system("clear");
            printf("------------- DESAFIO -------------\n");

            (*challenges[challenge])();

            bzero(buff, MAX);
            int n = read(sockfd, buff, sizeof(buff));

            if(n == -1 || n == 0)
                return;

            if(strcmp(buff, answers[challenge])== 0){
                retry = 0;
            }else{
                printf("Respuesta incorrecta: %s\n",buff);
            }

        }

    }

    printf("Felicitaciones, terminaste el desafío!\n");

} 
  

int main(){ 

    int sockfd, connfd, len; 
    struct sockaddr_in servaddr = {0};
    struct sockaddr_in cli = {0}; 

    srand(time(NULL));
  
    // Socket creation
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        fprintf(stderr, "Socket creation failed...\n"); 
        exit(0); 
    }
    
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
        fprintf(stderr, "Setsockopt(SO_REUSEADDR) failed");    
  
    // Assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Bind newly created socket to given IP
    if ((bind(sockfd, (SA* )&servaddr, sizeof(servaddr))) != 0) { 
        fprintf(stderr,"Socket bind failed...\n"); 
        exit(0); 
    } 
  
    // Now server is ready to listen
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    
    len = sizeof(cli); 
  
    // Accept the data packet from client
    connfd = accept(sockfd, (SA*)&cli, &len); 
    if (connfd < 0) { 
        printf("Server acccept failed...\n"); 
        exit(0); 
    } 
  
    // Function for chat 
    chat(connfd); 
  
    // Close the socket 
    close(sockfd);

} 