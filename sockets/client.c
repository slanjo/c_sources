#include <stdio.h>
#include <stdlib.h>

// can find the includes at the following directory: "/usr/include/linux/"
// netdb.h is located in /usr/include/ directory
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>  // includes inet_ntoa - among others

#include <netinet/in.h> // includes sockaddr_in

int main() {


	//create a socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0 );
	// specify an addrss for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(9002);      //specify a port

	server_address.sin_addr.s_addr = INADDR_ANY;//specify an address we're going to connect
        //	server_address.sin_addr.s_addr = inet_addr("192.168.80.128");//INADDR_ANY;//specify an address we're going to connect
	//connect returns an integer if value of 0 evertything OK, if 1 something went wrong = ERROR
	
	printf("The ip to connect is: %s\n\n", inet_ntoa(server_address.sin_addr));

	int connection_status = connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address));
	if (connection_status == -1) {
		printf("There was an error making a connection to the remote socket \n\n");
	}


	//receive data from the server
	
	char server_response[255];
	recv(network_socket, &server_response, sizeof(server_response), 0);
	

	// print out the data we got back from the server
	
	printf("Server Response: %s\n\n", server_response);
	
	// needs to be looked at: 
	close(network_socket);


	return 0;

}
