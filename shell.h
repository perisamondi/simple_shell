<<<<<<< HEAD
=======

>>>>>>> f374f7a0fa53344b2cc450bc3cd450afebcf71f6
#ifndef SHELL_H
#define SHELL_H
#include <stddef.h>
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
int locate_program(d_o_p *data);
char **split_path(d_o_p *data);
int ascertain_file(char *file_path);
void expand_variables(d_o_p *data);
void more_alias(d_o_p *data);
int append_str(char *buffer, char *str);
int display_alias(d_o_p *data, char *alias);
char *retrieve_alias(d_o_p *data, char *name);
int put_alias(char *alias_string, d_o_p *data);

int builtins1(d_o_p *data);

int myexit(d_o_p*data);
int mycd(d_o_p *data);
int mymkdir(d_o_p *data, char *new_dir);
int myhelp(d_o_p *data);
int another_alias(d_o_p *data);

int show_env(d_o_p *data);
int create_env(d_o_p *data);
int destroy_env(d_o_p *data);

char *get_env_var(char *env_var, d_o_p *data);
int env_set_key(char *key, char *value, d_o_p *data);
int env_delete_key(char *key, d_o_p *data);
void show_environ(d_o_p *data);

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
<<<<<<< HEAD
int _logic(char *ac[], int x , char opera[]);
void process_data(d_o_p *data, int argc, char *argv[], char **env);
void handle_ctrl_c(int opr UNUSED);
int main(int argc, char *argv[], char *env[]);
void prompter(char *prompt, d_o_p *data);
int run_prog(d_o_p *data);
#endif

=======
int _logic(char *ac[], int x, char opera[]);

#endif
>>>>>>> f374f7a0fa53344b2cc450bc3cd450afebcf71f6
