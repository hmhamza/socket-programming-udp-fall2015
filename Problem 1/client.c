#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT_NO 8888

int main(){

	int msg_len=100;
	char *msg=(char*)malloc(msg_len);
		
	struct sockaddr_in serv_addr;

	int sock=socket(AF_INET,SOCK_DGRAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(PORT_NO);
	serv_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

	strcpy(msg,"L12-4013 Hafiz Muhammad Hamza");
	sendto(sock,msg,msg_len,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	//close();

}

