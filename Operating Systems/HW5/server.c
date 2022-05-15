/*
    Neeha Hammad
    References:
    https://www.geeksforgeeks.org/socket-programming-cc/
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <time.h>
#define NUMCLIENT 3

typedef struct challenge
{
	char question[33];
	char answer[33];
}
challenge_t;

challenge_t client_challenges[3];

int my_fortune(int x)
{
	char buffer_new[33];
	char game[33];
	char ans[33];
	char temp[33];
	memset(ans, 0, 33);
	memset(buffer_new, 0, 33);
	memset(game, 0, 33);

	FILE *sentence_fd = popen("fortune -n 32 -s", "r");

	if (sentence_fd == NULL)
	{
		return -1;
	}
	else
	{

		fgets(temp, sizeof(temp), sentence_fd);
		printf("%s", temp);
		pclose(sentence_fd);
		memcpy(buffer_new, temp, 33);

		char *token = strtok(buffer_new, " ");
		int counter = 0;
		while (token != NULL)
		{
			counter++;
			token = strtok(NULL, " ");
		}

		int random = rand() % counter;
		memcpy(buffer_new, temp, 33);
		token = strtok(buffer_new, " ");
		//printf("Random: %d\n",random);
		//printf("Counter: %d\n",counter);
		//printf("New buffer: %s\n",buffer_new);
		memset(game, 0, 33);
		while (token != NULL)
		{

			//printf("While Random: %d, Token: %s\n", random, token); 
			random--;
			if (random == 0)
			{
				strcat(ans, token);

				int len = strlen(token);
				for (int i = 0; i < len; i++)
				{
					strcat(game, "_");
				}
			}
			else
			{

				strcat(game, token);
			}
			strcat(game, " ");
			token = strtok(NULL, " ");
		}
		strcpy(client_challenges[x].question, game);
		strcpy(client_challenges[x].answer, ans);

		//printf("C: %s\n",buffer_new);
		//printf("Qs: %s\n", game);
		//printf(" Ans: %s\n",ans);
	}
	return 0;
}
int main(int argc, char
	const *argv[])
{
	fd_set readfds;
	int client_sockets[3];
	int file_descriptor;
	int server_fd, new_socket, valread;
	struct sockaddr_in address;
	int opt = 1;
	int addrlen = sizeof(address);
	char buffer[1024] = { 0 };

	char *correct = "O: Congratulation - challenge passed!";
	char *wrong = ("F: Wrong guess - expected: ");
	char *qs = "C: ";
	char *ending = "M: You mastered 1/1 challenges. Good bye!";
	char *error = "Sorry, Invalid Starting Character ";
	char *greetings[2] = { "M: Guess the missing ____!\n", "M: Send your guess in the form 'R: word\\r\\n'.\n" };

	if (argc < 2)
	{
		printf("Error: Port Number Not Provided\n");
		return EXIT_FAILURE;
	}
	else if (argc > 2)
	{
		printf("Invalid Number of Arguments\n");
		return EXIT_FAILURE;
	}

	int port = atoi(argv[1]);
	if (port <= 0 || port > 65535)
	{
		printf("Invalid Port Number\n");
		return EXIT_FAILURE;
	}
	//resetting
	for (int i = 0; i < NUMCLIENT; i++)
	{
		client_sockets[i] = 0;
	}
	// Creating socket file descriptor 
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
	{
		perror("socket failed");
		exit(EXIT_FAILURE);
	}

	// Forcefully attaching socket to the port 
	if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
	{
		perror("setsockopt");
		exit(EXIT_FAILURE);
	}
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);

	// Forcefully attaching socket to the port 
	if (bind(server_fd, (struct sockaddr *) &address,
			sizeof(address)) < 0)
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	if (listen(server_fd, 3) < 0)
	{
		perror("listen");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		//clear the socket set  
		FD_ZERO(&readfds);
		FD_SET(server_fd, &readfds);

		//max file descriptors +1
		int max_fd = server_fd;
		for (int i = 0; i < NUMCLIENT; i++)
		{
			file_descriptor = client_sockets[i];

			if (file_descriptor > 0)
			{
				FD_SET(file_descriptor, &readfds);
			}
			if (file_descriptor > max_fd)
			{
				max_fd = file_descriptor;
			}
		}

		int return_value = select(max_fd + 1, &readfds, NULL, NULL, NULL);

		if (return_value == -1)
		{
			printf("Select Error\n");
		}
		if (FD_ISSET(server_fd, &readfds))
		{
			if ((new_socket = accept(server_fd, (struct sockaddr *) &address,
					(socklen_t*) &addrlen)) < 0)
			{
				perror("accept");
			}

			send(new_socket, greetings[0], strlen(greetings[0]), 0);
			send(new_socket, greetings[1], strlen(greetings[1]), 0);

			//sending the challenge to the client
			for (int i = 0; i < NUMCLIENT; i++)
			{
				if (client_sockets[i] == 0)
				{
					my_fortune(i);
					client_sockets[i] = new_socket;
					send(new_socket, qs, strlen(qs), 0);
					send(new_socket, client_challenges->question, strlen(client_challenges->question), 0);
					break;
				}
			}
		}

		//obtaining client's answers
		for (int i = 0; i < NUMCLIENT; i++)
		{
			file_descriptor = client_sockets[i];
			if (file_descriptor == 0)
			{
				continue;
			}

			//if data is in socket
			if (FD_ISSET(file_descriptor, &readfds))
			{
				memset(buffer, 0, 1024);
				valread = read(file_descriptor, buffer, 1024);
				//if there's nothing to read, we close the connection
				if (valread == 0)
				{
					close(file_descriptor);
					client_sockets[i] = 0;
					continue;
				}
				printf("%s\n", buffer);

				//checking &comparing client's answers
				if (buffer[0] == 'R')
				{
					printf("ans len %ld, buff len %ld\n", strlen(client_challenges->answer), (strlen(buffer) - 4));
					if (strlen(client_challenges->answer) == (strlen(buffer) - 4))
					{
						char store[100];
						for (int i = 1; i <= strlen(client_challenges->answer); i++)
						{
							store[i - 1] = buffer[2 + i];
						}

						//store[strcspn(store,"\r\n")] = 0;

						store[strlen(store) - 2] = '\0';
						//printf("Buffer: %s\n", buffer);
						//printf("STORE: %s\n",store);
						//printf("ANSWER: %s\n",client_challenges->answer);

						if (strcmp(store, client_challenges->answer) == 0)
						{
							send(file_descriptor, correct, strlen(correct), 0);
							//printf("O: Congratulation - challenge passed!\n");
						}
						else
						{
						 	//printf("STORE: %s\n",store);
							//printf("ANSWER: %s\n",client_challenges->answer);
							send(file_descriptor, wrong, strlen(wrong), 0);
							send(file_descriptor, client_challenges->answer, strlen(client_challenges->answer), 0);
						}
						//printf("Wrong guess - expected: %s",client_challenges->answer);}
					}
					else
					{
						send(file_descriptor, wrong, strlen(wrong), 0);
						send(file_descriptor, client_challenges->answer, strlen(client_challenges->answer), 0);
					}
					//{printf("Wrong guess - expected: %s",client_challenges->answer);}
				}
				else if (buffer[0] == 'Q')
				{
					send(file_descriptor, ending, strlen(ending), 0);
					exit(1);
				}
				else
				{
					send(file_descriptor, error, strlen(error), 0);
					exit(1);
				}
			}
		}
	}
	return 0;
}
