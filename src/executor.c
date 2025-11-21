#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../include/executor.h"

void execute_command(char **args) {
	pid_t pid;
	int status;

	pid = fork();

	if (pid < 0) {
		perror("fork failed");
		return;
	}

	if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("execvp failed");
		}
		exit(EXIT_FAILURE);
	}
	else {
		waitpid(pid, &status, 0);
	}
}
