#include "main.h"

/**
 * display_alias - this function will handle aliases
 * @data: is the program's data
 * @alias: is the name of the alias to be printed
 * Return: 0
 */
int display_alias(data_of_program *data, char *alias)
{
	int j, k, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_len(alias);
		for (j = 0; data->alias_list[j]; j++)
		{
			if (!alias || (str_compare(data->alias_list[i], alias, alias_length)
				&&	data->alias_list[i][alias_length] == '='))
			{
				for (k = 0; data->alias_list[j][k]; k++)
				{
					buffer[k] = data->alias_list[j][k];
					if (data->alias_list[j][k] == '=')
						break;
				}
				buffer[k + 1] = '\0';
				append_str(buffer, "'");
				append_str(buffer, data->alias_list[j] + k + 1);
				append_str(buffer, "'\n");
				_print(buffer);
			}
		}
	}

	return (0);
}

/**
 * retrieve_alias - will handle aliases
 * @data: is the struct for the program's data
 * @name: is the name of the requested alias.
 * Return: 0
 */
char *retrieve_alias(data_of_program *data, char *name)
{
	int j, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_len(name);

	for (j = 0; data->alias_list[j]; j++)
	{
		if (str_compare(name, data->alias_list[i], alias_length) &&
			data->alias_list[j][alias_length] == '=')
		{
			return (data->alias_list[j] + alias_length + 1);
		}
	}
	return (NULL);

}

/**
 * put_alias - implements alias
 * @alias_string: is the value
 * @data: is the struct for the program's data
 * Return: 0
 */
int put_alias(char *alias_string, data_of_program *data)
{
	int j, k;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (j = 0; alias_string[j]; j++)
		if (alias_string[j] != '=')
			buffer[j] = alias_string[j];
		else
		{
			temp = retrieve_alias(data, alias_string + j + 1);
			break;
		}

	for (k = 0; data->alias_list[k]; k++)
		if (str_compare(buffer, data->alias_list[k], j) &&
			data->alias_list[k][j] == '=')
		{
			free(data->alias_list[k]);
			break;
		}

	if (temp)
	{
		append_str(buffer, "=");
		append_str(buffer, temp);
		data->alias_list[k] = str_dup(buffer);
	}
	else
		data->alias_list[k] = str_dup(alias_string);
	return (0);
}
