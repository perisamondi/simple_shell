#include "shell.h"
/**
 * main - built in shell
 * argc - number of arguments
 * @argv : pointer to argument vector 
 * @envp : environment pointer
 * Return : 0  on success
 */
int main(int argc, char **argv[], char **envp[])
{
	char *line;
	ssize_t x;
	size_t  n = 20, f =0, y=4;
	char *num, *tar;

	if (argc  > 1)
		argv[1] =  NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO))
                printf("cisfun$ ");
		num =  malloc(sizeof(char) * n);
                x = getline(&num, &n, stdin);
                        if (x == -1)
                        {
                                free(num);
                                exit(EXIT_FAILURE);
			}
	}
	if (*num != '\n')
	{
		line = strtok(num);
		if (strcmp("exit",line[0] == 0))
		{		
			break;
		}
		tar = file(line[0]);
		if (f == 0 && tar == NULL)
			line[0]= tar;
			y = path(line[0]);
			if (y == 1)
				_fork(line,envp);
				if (tar == NULL && y == 0 && f == 0)
				printf("No such file or directory");
				}
				free(tar);
				free(num);
				free(line);
				exit (0);
}
