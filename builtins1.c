#include "main.h"

/**
 * show_env - will display env
 * @data: is the struct for the program's data
 * Return: 0
 */
int show_env(data_of_program *data)
{
	int a;
	char cpname[50] = {'\0'};
	char *var_copy = NULL;

	if (data->tokens[1] == NULL)
		show_environ(data);
	else
	{
		for (a = 0; data->tokens[1][a]; a++)
		{
			if (data->tokens[1][a] == '=')
			{
				var_copy = str_dup(get_env_var(cpname, data));
				if (var_copy != NULL)
					env_set_key(cpname, data->tokens[1] + a + 1, data);

				show_environ(data);
				if (get_env_var(cpname, data) == NULL)
				{
					_print(data->tokens[1]);
					_print("\n");
				}
				else
				{
					env_set_key(cpname, var_copy, data);
					free(var_copy);
				}

				return (0);
			}
			cpname[a] = data->tokens[1][a];
		}
		errno = 2;
		perror(data->command_name);
		errno = 127;
	}
	return (0);
}

/**
 * create_env - will set up env
 * @data: is the program's data
 * Return: 0
 */
int create_env(data_of_program *data)
{
	if (data->tokens[1] == NULL || data->tokens[2] == NULL)
		return (0);
	if (data->tokens[3] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}

	env_set_key(data->tokens[1], data->tokens[2], data);

	return (0);
}

/**
 * destroy_env - will unset env
 * @data: is the program's data'
 * Return: 0
 */
int destroy_env(data_of_program *data)
{
	if (data->tokens[1] == NULL)
		return (0);
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	env_delete_key(data->tokens[1], data);

	return (0);
}

/**
 * builtins1 - are the functions to find matches and run
 * @data: is the struct for the program's data
 * Return: func exceecuted or -1
 */
int builtins1(data_of_program *data)
{
	int iterator;
	builtins options[] = {
		{"exit", myexit},
		{"help", myhelp},
		{"cd", mycd},
		{"alias", another_alias},
		{"env", show_env},
		{"setenv", create_env},
		{"unsetenv", destroy_env},
		{NULL, NULL}
	};

	for (iterator = 0; options[iterator].builtin != NULL; iterator++)
	{
		if (str_compare(options[iterator].builtin, data->command_name, 0))
		{
			return (options[iterator].function(data));
		}
	}
	return (-1);
}
