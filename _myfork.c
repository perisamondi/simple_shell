#include "shell.h"
/**
 * _fork- system execute  using fork function
 * @cat: array  gotten from command line
 * envp: environment pointer
 * Return : void
 */
void _fork(char **cat , char *envp[])
{
	pid_t cdir;
	int status;

	 cdir = fork();
        if (cdir < 0)
                {
                        perror("fork issue error");
			return;
                }
                if (cdir == 0)
                {
                      if (execve(cat[0], cat, envp) == -1)
                        printf("No such file or directory%s\n",);
		}
		else
			wait(&status);
}
