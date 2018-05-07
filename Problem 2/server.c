#include<stdio.h>
#include<unistd.h>

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>


#define PORT_NO 8888
#define IP "127.0.0.1"
int main(){

	int msg_len=100,i,j,count=0;
	char *msg_send=(char*)malloc(msg_len);
	char *msg_rec=(char*)malloc(msg_len);
	
	char LIST[100][10];
		
	struct sockaddr_in serv_addr;

	int sock=socket(AF_INET,SOCK_DGRAM,0);
	serv_addr.sin_family=AF_INET;
	serv_addr.sin_port=htons(PORT_NO);
	serv_addr.sin_addr.s_addr=inet_addr(IP);

	int sockaddr_len=sizeof(serv_addr);

	bind(sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

	while(1){
		recvfrom(sock,msg_rec,msg_len,0,(struct sockaddr*)&serv_addr,&sockaddr_len);
		for(i=0;msg_rec[i]!=' ';i++)
			msg_send[i]=msg_rec[i];

		msg_send[i]='\0';

		strcat(msg_send," Welcome Aboard!\n");
		sendto(sock,msg_send,msg_len,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));

		recvfrom(sock,msg_rec,msg_len,0,(struct sockaddr*)&serv_addr,&sockaddr_len);
		
		for(i=0;msg_rec[i]!=' ';i++);
		
		char rollNo[10];

		for(i++,j=0;msg_rec[i]!='\0';i++,j++)
			rollNo[j]=msg_rec[i];

		rollNo[j]='\0';
		
		printf("\n\tCURRENT LIST CONTAINS %i ROLL NOS\n ",count);
		for(i=0;i<count;i++)
			printf("\n#%i %s",i+1,LIST[i]);

		for(i=0;i<count;i++)
			if(strcmp(rollNo,LIST[i])==0){
				msg_send[0]='\0';
				strcpy(msg_send,"[");
				strcat(msg_send,rollNo);
				strcat(msg_send,"] You've checked in already!");
				sendto(sock,msg_send,msg_len,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
				break;
			}
	
		if(i==count){
			strcpy(LIST[count],rollNo);
			count++;
			msg_send[0]='\0';
			strcpy(msg_send,"[");
			strcat(msg_send,rollNo);
			strcat(msg_send,"] You haven't checked in yet!");
			sendto(sock,msg_send,msg_len,0,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
		}

		printf("\n\n");

	}	

}

