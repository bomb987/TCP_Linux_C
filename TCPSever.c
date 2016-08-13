/*
*author by 孙晨昊
*2016/5/27
*/
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#define PORT 3339
int main()
{
	char buf[256];
	int s_fd, c_fd;
	int s_len, c_len;
	struct sockaddr_in s_addr;
	struct sockaddr_in c_addr;
	s_fd = socket(AF_INET,SOCK_STREAM,0);
	s_addr.sin_family = AF_INET;
	s_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	s_addr.sin_port = PORT;
	s_len = sizeof(s_addr);
	bind(s_fd, (struct sockaddr *) &s_addr, s_len);
	listen(s_fd, 10);
	while(1)
	{
	        char *sendbuf="thanks";
		printf("please wait a moment!\n");
		c_len = sizeof(c_addr);
		c_fd = accept(s_fd,(struct sockaddr *) &c_addr,(socklen_t*__restrict) &c_len);
		recv(c_fd, buf, 256, 0);
		buf[sizeof(buf)+1]='\0';
		printf("recieve message:\n %s\n",buf);
		send(c_fd,sendbuf,sizeof(sendbuf),0);
		close(c_fd);
	}
}
		
