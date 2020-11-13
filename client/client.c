#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h> 

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr

/*
    La forma general de implementar el servidor fue sacada del sitio geeksforgeeks
    https://www.geeksforgeeks.org/tcp-server-client-implementation-in-c/
*/


void chat(int sockfd);
 

int main() {
	int sockfd; 
	struct sockaddr_in servaddr = {0};

	// Socket creation
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("Socket creation failed\n"); 
		exit(0); 
	} 
	
	printf("Socket successfully created\n"); 

	// Assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// Connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("Connection with the server failed\n"); 
		exit(0); 
	} 
	
	printf("Connected to the server\n"); 

	// Function for chat 
	chat(sockfd); 

	// Close the socket 
	close(sockfd); 
} 


void chat(int sockfd){
	char buff[MAX] = {0};

	
	int len = 0;
	char c = '\n';
	while(c == '\n') {
		do {
			c = getchar();
			if(c != EOF)
				buff[len++] = c;
		} while(c != '\n' && c != EOF);
		if(c == EOF) //Pues la ultima linea de respuestas.txt no tiene salto de liena
			buff[len++] = '\n';
		buff[len++] = 0;
		if(len > 2) {
			//Bash siempre lee una linea extra vacia
			printf("%s", buff);
			write(sockfd, buff, len);
		}
		len = 0;		
	}
	exit(0);
}
