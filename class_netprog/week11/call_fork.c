#include<stdio.h>
#include<unistd.h>

int g = 10;

int main(void) {
	int l = 20;
	l += 5;
	g += 1;

	pid_t pid = fork();
	if (pid == 0)
		g += 1;
	else
		l += 1;

	printf("PID | %d g : %d\n", pid, g);
	printf("PID | %d l : %d\n", pid, l);
	return 0;
}
