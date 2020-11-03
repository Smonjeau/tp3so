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


void func(int sockfd);
 

int main() {
	int sockfd, connfd; 
	struct sockaddr_in servaddr = {0};
	struct sockaddr_in cli = {0}; 

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

	// function for chat 
	func(sockfd); 

	// close the socket 
	close(sockfd); 
} 


void func(int sockfd){
	char buff[MAX] = {0}; 

	while(1) { 
		printf("Enter the string : "); 
		
		int n = 0; 
		while ((buff[n++] = getchar()) != '\n');
		
		printf("%s", buff);
		write(sockfd, buff, n);

/*		read(sockfd, buff, sizeof(buff)); 
		printf("From Server : %s", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Client Exit...\n"); 
			break; 
		} */
	} 
}