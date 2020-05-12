#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

void zombie_handler(void);

int main(void) {
	pid_t pid;
	struct sigaction act;

	act.sa_handler = zombie_handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGCHLD, &act, 0);

	pid = fork();
	// ... page 242

	return 0;
}

void zombie_handler(void) {
	int status;
	int spid;
	spid = wait(&status);

	printf("PID: \t%d\n", spid);
	printf("exit value: \t%d\n", WEXITSTATUS(status));
	printf("exit state: \t%d\n", WIFEXITED(status));
}
