#include "shell.h"

/**
 * cue - creates a unix shell
 * getline - reads string from input
 * isatty- tests whether open file descriptor is terminal or command line
 * fork- create  acopy of the process
 * @ar : is the pointer to argument vector
 * @ev : ponter to the environment
 * returns 0 on success and -1 on failure
 */
void cue(char **ar, char **ev)
{
	char *line = NULL;
	ssize_t x;
	size_t f = 0;
	int i, h;
	char *argv[PIPE];
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
	}
	h = 0;
	argv[0] = strtok(line, " ");
	while (argv[h] != NULL)
	{
		h++;
		argv[h] = strtok(NULL, " ");
	}
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
