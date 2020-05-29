#include <stdio.h>
#include <stdlib.h>

// can find the includes at the following directory: "/usr/include/linux/"
// netdb.h is located in /usr/include/ directory
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#include <netinet/in.h> // includes sockaddr_in

int main() {

	char server_message[256] = "Your first client/server socket programs are running";


	int server_socket;
	// create server socket
	server_socket = socket(AF_INET, SOCK_STREAM , 0);
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));


	listen(server_socket, 5);

	int client_socket;

	client_socket = accept(server_socket, NULL, NULL);

	send(client_socket, server_message, sizeof(server_message), 0);

	//close the socket
	close(server_socket);


















	return 0;
}


