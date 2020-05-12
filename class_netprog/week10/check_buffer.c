#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
	int s;
	int opt, optlen = 4;

	s = socket(PF_INET, SOCK_STREAM, 0);

	// setting I/O buffer size
	opt = 100000;
	setsockopt(s, SOL_SOCKET, SO_SNDBUF, (void *)&opt, optlen);
	setsockopt(s, SOL_SOCKET, SO_RCVBUF, (void *)&opt, optlen);
	// ------

	getsockopt(s, SOL_SOCKET, SO_SNDBUF, (void *)&opt, &optlen);
	printf("Send buffer size: %d\n", opt);
	getsockopt(s, SOL_SOCKET, SO_RCVBUF, (void *)&opt, &optlen);
	printf("Recv buffer size: %d\n", opt);

	return 0;
}
