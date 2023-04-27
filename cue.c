#include "shell.h"

/**
 * cue - builds a basic shell 
 * @ar - argument vector 
 * @ev  -environment pointer
 * Return :  0 on successs & -1 on failure
 */

void cue(char **ar, char **ev)
{
	char *line;
        ssize_t x;
        size_t f;
        int n, h;
        char *argv[PIPE];
        int qstatus;
        pid_t cdir;

        while (1)
        {
                printf("thisisc$ ");

                x = getline(&line, &f, stdin);
                        if (x == -1)
                        {
                                free(line);
                                exit(EXIT_FAILURE);
                        }
			n = 0;
			while (line[n])
			{
				if(line[n] == '\n')
					line[n]= 0;
				n++;
			}
		h = 0;
        	argv[0] = strtok(line, " ");
			while (argv[h] != NULL)
			{
				argv[++h] = strtok(NULL, " ");
			}
		cdir = fork();
		if (cdir == -1)
		{
			free(line);
			exit(EXIT_FAILURE);
		}
		if (cdir == 0)
		{
			if (execve(argv[h], argv, ev) == -1)
			printf("%s:No such file or directory\n", ar[0]);
			else
				wait(&qstatus);
		}
	}
}
