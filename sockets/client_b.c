
/***SOCKET PROGRAMMING IN C*********
*FOLLOWING bjees.us guide and "Head First C"   
*  can find the includes at the following directory: "/usr/include/linux/"
* netdb.h is located in /usr/include/ directoryinclude <stdio.h>
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>     // This library contains: memset, ...
#include <netdb.h>  	// This library contains addrinfo, getaddrinfo(), ...
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>  // includes inet_ntoa - among others

#include <netinet/in.h> // includes sockaddr_in

int main(int argc, char *argv[]) {

	struct addrinfo hints, *res, *p;
	int sd, s, status, j; 	// sd = socket file discriptor
	char ipstr[INET6_ADDRSTRLEN];
	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = 0;
	hints.ai_flags = AI_PASSIVE;
	if (argc != 3) {
		fprintf(stderr, "The usage is: ./client <IP ADDRESS> <PORT>\n");
		printf("argc = %d\n", argc);
		return 1;
	}


	printf("hints.ai_family is: %s\n", hints.ai_family);
	if ((status = getaddrinfo( argv[1], argv[2], &hints, &res))!= 0)  { // check if address info obtained the IPs
	       								    // and let user know if it didn't.
		
		fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
		return 2;
	}
	
	for(p = res; p != NULL; p = p->ai_next) {
		void *addr;
		char *ipver;
		if( p->ai_family == AF_INET ) {
			struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
			addr = &(ipv4->sin_addr);
			ipver = "IPv4";
		}
		

		else { //IPv6
	       	 	struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
			addr = &(ipv6->sin6_addr);
			ipver = "IPv6";
		}
		
		inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);	
		printf("raw address: %s, %s\n", ipver, ipstr );


		
	}



//	sd = socket("
	printf("a+++---rgv[0] = %s\n+++---argv[1] = %s\n+++---rgv[2] = %s\n", argv[0], argv[1], argv[2]);
	printf("hints.ai_family is: %s\n", hints.ai_family);
	



	return 0;

}
