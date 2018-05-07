#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>

#define PORT_NO 8888
#define IP "127.0.0.1"
int main(){

	int msg_len=100,i;
	char *msg_send=(char*)malloc(msg_len);
	char *msg_rec=(char*)malloc(msg_len);
	char *input=(char*)malloc(msg_len);
	char rollNo[10];	
	struct sockaddr_in serv_addr;

	int sock=socket(AF_INET,SOCK_DGRAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(PORT_NO);
	serv_addr.sin_addr.s_addr=inet_addr(IP);

	int sockaddr_len=sizeof(serv_addr);

	bind(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	
	while(1){
		printf("Enter Input (ROLL NO NAME): ");
		gets(input);
		strcpy(msg_send,input);
		sendto(sock,msg_send,msg_len,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
	
		recvfrom(sock,msg_rec,msg_len,0,(struct sockaddr*)&serv_addr,&sockaddr_len);
		printf("\n%s\n",msg_rec);

		for(i=0;input[i]!=' ';i++)
			rollNo[i]=input[i];

		rollNo[i]='\0';

		msg_send[0]='\0';		
		
		strcpy(msg_send,"CHECK: ");
		strcat(msg_send,rollNo);
		sendto(sock,msg_send,msg_len,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

		recvfrom(sock,msg_rec,msg_len,0,(struct sockaddr*)&serv_addr,&sockaddr_len);
		printf("%s\n",msg_rec);

		printf("\n\n");

	}
}

