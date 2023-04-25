#include "shell.h"
/***
 * strtok - breaks  a string into sequence of tokens
 * @ar : argument vector 
 * @ev : environment pointer
 * returns pointer to null terminate string token
 */
void cue(char **ar, char **ev)
{
	ssize_t x;
	size_t f = 0;
	int i, h;
	char *argv[] = {PIPE 1024, NULL};
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
"cue.c" 48L, 687C                               
