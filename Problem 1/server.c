#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>


#define PORT_NO 8888
#define IP "127.0.0.1"
int main(){

	int msg_len=100,i;
	char *msg=(char*)malloc(msg_len);
		
	struct sockaddr_in serv_addr;

	int sock=socket(AF_INET,SOCK_DGRAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(PORT_NO);
	serv_addr.sin_addr.s_addr=inet_addr(IP);
	bind(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	
	int sockaddr_len=sizeof(serv_addr);

	recvfrom(sock,msg,msg_len,0,(struct sockaddr*)&serv_addr,&sockaddr_len);
	
	
		printf("\n\t*** Received from Client ***\n");
		printf("\nIP: %s",IP);
		printf("\nPort# %i",PORT_NO);
		printf("\nROLL NO: ");
		for(i=0;msg[i]!=' ';i++)
			printf("%c",msg[i]);

		printf("\nNAME: ");
		for(i++;msg[i]!='\0';i++)
			printf("%c",msg[i]);		

		printf("\n\n\n");
	

}

