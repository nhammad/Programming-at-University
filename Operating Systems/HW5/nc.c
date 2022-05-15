/*
    Neeha Hammad
    References:
    https://www.geeksforgeeks.org/socket-programming-cc/
*/

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>

int main(int argc, char
	const *argv[])
{
	//set of all file discriptors
	fd_set readfds;

	if (argc < 3)
	{
		printf("Error: Port Number Not Provided\n");
		return EXIT_FAILURE;
	}
	else if (argc > 3)
	{
		printf("Invalid Number of Arguments\n");
		return EXIT_FAILURE;
	}

	int port = atoi(argv[2]);
	if (port <= 0 || port > 65535)
	{
		printf("Invalid Port Number\n");
		return EXIT_FAILURE;
	}

	int sock = 0, valread;
	struct sockaddr_in serv_addr;
	char buffer[1024] = { 0 };
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		return -1;
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(port);

	// Convert IPv4 and IPv6 addresses from text to binary form 
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
		printf("\nInvalid address/ Address not supported \n");
		return -1;
	}

	if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		printf("\nConnection Failed \n");
		return -1;
	}

	while (1)
	{
		//clear the socket set  
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
		FD_SET(sock, &readfds);
		//max file descriptors +1
		int return_value = select(sock + 1, &readfds, NULL, NULL, NULL);
		if (return_value == -1)
		{
			printf("Select Error\n");
		}
		//if data is in socket
		else if (FD_ISSET(sock, &readfds))
		{
			//without this, characters turncate
			memset(buffer, 0, 1024);
			valread = read(sock, buffer, 1024);
			//only prints if data is > 0
			if (valread > 0)
			{
				printf("%s\n", buffer);
			}
		}
		else if (FD_ISSET(0, &readfds))
		{
			memset(buffer, 0, 1024);
			valread = read(0, buffer, 1024);
			if (valread > 0)
			{
				send(sock, buffer, strlen(buffer), 0);
			}
		}
	}
	return 0;
}
