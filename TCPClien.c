/*
*author by 孙晨昊
*2016/5/27
*/
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 3339
int main()
{
	int sockfd;
	int len;
	struct sockaddr_in addr;
	int newsockfd;
	char *buf;
	char s[20];
	fgets(s,20,stdin);
	buf=s;
	int len2;
	char rebuf[40];
	sockfd = socket(AF_INET,SOCK_STREAM,0);
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr=htonl(INADDR_ANY);
	addr.sin_port = PORT;
	len = sizeof(addr);
	newsockfd = connect(sockfd,(struct sockaddr *)&addr, len);
	if(newsockfd==-1)
	{
		perror("链接失败");
		return 1;
	}
	len2 = sizeof(buf);
	send(sockfd,buf,len2,0);
	sleep(10);
	recv(sockfd,rebuf,256,0);
	printf("recieve message:\n%s\n",rebuf);
	close(sockfd);
	return 0;
}
