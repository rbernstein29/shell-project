#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/parser.h"
#include "../include/executor.h"

#define MAX_INPUT 1024


int main() {
	char input[MAX_INPUT];
	char *args[MAX_ARGS];
	int argc;

	while (1) {
		printf("rb_shell> ");
		fflush(stdout);

		if (fgets(input, MAX_INPUT, stdin) == NULL) {
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		if (strlen(input) == 0) {
			continue;
		}

		argc = parse_input(input, args);
		
		if (argc == 0) {
			continue;
		}
		
		if (strcmp(args[0], "exit") == 0) {
			break;
		}

	 	execute_command(args);	
	}
	return 0;
}
