#include "shell.h"
/**
 *
 */
void cue(char **ar, char **ev)
{
	char *line = NULL;
	ssize_t x;
	size_t f = 0;
	int i;
	char *argv[] = {NULL, NULL};
	int status;
	pid_t cdir;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		printf("cisfun$ ");

		x = getline(&line, &f, stdin);
			if (x == -1)
			{
				free(line);
				exit(EXIT_FAILURE);
			}
			i = 0;
			while (line[i])
			{
				if (line[i] == '\n')
				line[i] = 0;
				i++;
			}
			argv[0] = line;
			cdir = fork();
			if (cdir == -1)
			{
				free(line);
			exit(EXIT_FAILURE);
			}
			if (cdir == 0)
			{
				if (execve(argv[0], argv, ev) == -1)
				printf("No such file or directory%s\n", ar[0]);
			}
			else
				wait(&status);
	}
}
