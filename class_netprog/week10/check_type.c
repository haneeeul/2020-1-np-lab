#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
	int tcp_sock, udp_sock;
	int opt, optlen = 4;

	tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
	udp_sock = socket(PF_INET, SOCK_DGRAM, 0);

	printf("SOCK_STREAM: %d\n", SOCK_STREAM);
	printf("SOCK_DGRAM: %d\n", SOCK_DGRAM);

	getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void *)&opt, &optlen);
	printf("Socket %d : %d\n", tcp_sock, opt);
	
	getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, (void *)&opt, &optlen);
	printf("Socket %d : %d\n", udp_sock, opt);

	return 0;
}
