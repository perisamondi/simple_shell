#include "shell.h"

/**
 * locate_program - ..
 * @data: the program's data
 * Return: 0
 */

int locate_program(d_o_p *data)
{
	int c = 0, ret_code = 0;
	char **directories;

	if (!data->command_name)
		return (2);

	if (data->command_name[0] == '/' || data->command_name[0] == '.')
		return (ascertain_file(data->command_name));

	free(data->tokens[0]);
	data->tokens[0] = str_join(str_dup("/"), data->command_name);
	if (!data->tokens[0])
		return (2);

	directories = split_path(data);

	if (!directories || !directories[0])
	{
		errno = 127;
		return (127);
	}

	for (c = 0; directories[c]; c++)
	{
		directories[c] = str_join(directories[c], data->tokens[0]);
		ret_code = ascertain_file(directories[c]);
		if (ret_code == 0 || ret_code == 126)
		{
			errno = 0;
			free(data->tokens[0]);
			data->tokens[0] = str_dup(directories[c]);
			free_pointers_array(directories);
			return (ret_code);
		}
	}
	free(data->tokens[0]);
	data->tokens[0] = NULL;
	free_pointers_array(directories);
	return (ret_code);
}

/**
 * split_path - will split the path in directories
 * @data: is the program's data
 * Return: directories
 */

char **split_path(d_o_p *data)
{
	int c = 0;
	int counter_directories = 2;
	char **tokens = NULL;
	char *PATH;

	PATH = get_env_var("PATH", data);
	if ((PATH == NULL) || PATH[0] == '\0')
	{
		return (NULL);
	}

	PATH = str_dup(PATH);

	for (c = 0; PATH[c]; c++)
	{
		if (PATH[c] == ':')
			counter_directories++;
	}

	tokens = malloc(sizeof(char *) * counter_directories);

	c = 0;
	tokens[c] = str_dup(_strtok(PATH, ":"));
	while (tokens[c++])
	{
		tokens[c] = str_dup(_strtok(NULL, ":"));
	}

	free(PATH);
	PATH = NULL;
	return (tokens);

}

/**
 * ascertain_file - will check the file
 * @file_path: is the path of the file
 * Return: 0
 */

int ascertain_file(char *file_path)
{
	struct stat sb;

	if (stat(file_path, &sb) != -1)
	{
		if (S_ISDIR(sb.st_mode) ||  access(file_path, X_OK))
		{
			errno = 126;
			return (126);
		}
		return (0);
	}
	errno = 127;
	return (127);
}
