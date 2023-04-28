#include "main.h"

/**
 * myexit - functions to close the prog
 * @data: is the struct for the program's data
 * Return: 0 or error
 */
int myexit(data_of_program *data)
{
	int a;

	if (data->tokens[1] != NULL)
	{
		for (a = 0; data->tokens[1][a]; a++)
			if ((data->tokens[1][a] < '0' || data->tokens[1][a] > '9')
				&& data->tokens[1][a] != '+')
			{
				errno = 2;
				return (2);
			}
		errno = _atoi(data->tokens[1]);
	}
	free_data(data);
	exit(errno);
}

/**
 * mycd - will change directory
 * @data: is the struct for the program's data
 * Return: 0 or error
 */
int mycd(data_of_program *data)
{
	char *dir_home = get_env_var("HOME", data), *dir_old = NULL;
	char old_dir[128] = {0};
	int error_code = 0;

	if (data->tokens[1])
	{
		if (str_compare(data->tokens[1], "-", 0))
		{
			dir_old = get_env_var("OLDPWD", data);
			if (dir_old)
				error_code = mymkdir(data, dir_old);
			_print(get_env_var("PWD", data));
			_print("\n");

			return (error_code);
		}
		else
		{
			return (mymkdir(data, data->tokens[1]));
		}
	}
	else
	{
		if (!dir_home)
			dir_home = getcwd(old_dir, 128);

		return (mymkdir(data, dir_home));
	}
	return (0);
}

/**
 * mymkdir - will create dir
 * @data: is the struct for the program's data
 * @new_dir: implementation
 * Return: 0 or error
 */
int mymkdir(data_of_program *data, char *new_dir)
{
	char old_dir[128] = {0};
	int err_code = 0;

	getcwd(old_dir, 128);

	if (!str_compare(old_dir, new_dir, 0))
	{
		err_code = chdir(new_dir);
		if (err_code == -1)
		{
			errno = 2;
			return (3);
		}
		env_set_key("PWD", new_dir, data);
	}
	env_set_key("OLDPWD", old_dir, data);
	return (0);
}

/**
 * myhelp - will display env
 * @data: is the struct for the program's data
 * Return: 0 or error
 */
int myhelp(data_of_program *data)
{
	int a, length = 0;
	char *mensajes[6] = {NULL};

	mensajes[0] = HELP_MSG;

	if (data->tokens[1] == NULL)
	{
		_print(mensajes[0] + 6);
		return (1);
	}
	if (data->tokens[2] != NULL)
	{
		errno = E2BIG;
		perror(data->command_name);
		return (5);
	}
	mensajes[1] = HELP_EXIT_MSG;
	mensajes[2] = HELP_ENV_MSG;
	mensajes[3] = HELP_SETENV_MSG;
	mensajes[4] = HELP_UNSETENV_MSG;
	mensajes[5] = HELP_CD_MSG;

	for (a = 0; mensajes[a]; a++)
	{
		length = str_len(data->tokens[1]);
		if (str_compare(data->tokens[1], mensajes[a], length))
		{
			_print(mensajes[a] + length + 1);
			return (1);
		}
	}
	errno = EINVAL;
	perror(data->command_name);
	return (0);
}

/**
 * another_alias - will handle the alias
 * @data: is the struct for the program's data
 * Return: 0
 */
int another_alias(data_of_program *data)
{
	int a = 0;

	if (data->tokens[1] == NULL)
		return (display_alias(data, NULL));

	while (data->tokens[++a])
	{
		if (count_char(data->tokens[a], "="))
			put_alias(data->tokens[a], data);
		else
			display_alias(data, data->tokens[a]);
	}

	return (0);

}
