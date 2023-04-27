#include "shell.h"

/**
 * cue - builds a basic shell 
 * @ar - argument vector 
 * @ev  -environment pointer
 * Return :  0 on successs 
 */

void cue(char **ar, char **ev)
{
	char *line;
        ssize_t x;
        size_t f = 0;
	int n ,h;
        char *argv[PIPE];
        int qstatus;
        pid_t cdir;


        while (1)
        {
		if (isatty(STDIN_FILENO))
		printf("thisisc$ ");
             x = getline(&line, &f, stdin);
                        if (x == -1)
                        {
                                free(line);
                                exit(EXIT_FAILURE);
                        }
			while (line[n])
			{
				if (line[n] == '\n')
					line[n] = 0;
				n++;
			}
			h = 0;
		       argv[0]	= strtok(line, " ");
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
			printf("%s:No such file or directory\n", ar[0]);
			else
				wait(&qstatus);
		}
	}
}
