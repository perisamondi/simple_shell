
#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>


#include "pipe.h"
typedef struct info
{
char *program_name;
char *input_line;
char *command_name;
int exec_counter;
int file_descriptor;
char **tokens;
char **env;
char **alias_list;
} d_o_p;
typedef struct builtins
{
char *builtin;
int (*function)(d_o_p *data);
} builtins;

void free_data(d_o_p *data);
void numstr(long num, char *str, int base);
int _atoi(char *dwell);
int count(char *str, char *chars);
void frec_data(d_o_p *data);
void fpointer(char **array);
int print(char *ptr);
int _print(char  *ptr);
int printerror(int ecode, d_o_p *data);
int _getline(d_o_p *data);
int str_comp(char *str1, char *str2, int number);
char *str_dup(char *str);
char *str_join(char *str1, char *str2);
void str_rev(char *str);
char *_strtok(char *line, char *delimator);
void split_str(d_o_p *data);
int _strlen(char *str);
int _logic(char *ac[], int x, char opera[]);

#endif
