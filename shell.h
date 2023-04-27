#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>

#define PIPE 40

void cue(char **ar , char **ev);
int main(int ac, char **ar, char **ev);
char *file(char *cx);
int path(char *cx);
#endif
