#include "main.h"

/**
 * display_alias - this function will handle aliases
 * @data: is the program's data
 * @alias: is the name of the alias to be printed
 * Return: 0
 */

int display_alias(data_of_program *data, char *alias)

{
	int a, b, alias_length;
	char buffer[250] = {'\0'};

	if (data->alias_list)
	{
		alias_length = str_len(alias);

		for (a = 0; data->alias_list[a]; a++)
		{
			if (!alias || (str_compare(data->alias_list[a], alias, alias_length)
				&&	data->alias_list[a][alias_length] == '='))
			{
				for (a = 0; data->alias_list[a][b]; b++)
				{
					buffer[b] = data->alias_list[a][b];
					if (data->alias_list[a][b] == '=')
						break;
				}
				buffer[b + 1] = '\0';
				append_str(buffer, "'");
				append_str(buffer, data->alias_list[a] + b + 1);
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
	int a, alias_length;

	if (name == NULL || data->alias_list == NULL)
		return (NULL);

	alias_length = str_len(name);

	for (a = 0; data->alias_list[a]; a++)

	{
		if (str_compare(name, data->alias_list[a], alias_length) &&
			data->alias_list[a][alias_length] == '=')
		{
			return (data->alias_list[a] + alias_length + 1);
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
	int a, b;
	char buffer[250] = {'0'}, *temp = NULL;

	if (alias_string == NULL ||  data->alias_list == NULL)
		return (1);
	for (a = 0; alias_string[a]; a++)
		if (alias_string[a] != '=')
			buffer[a] = alias_string[a];
		else
		{
			temp = retrieve_alias(data, alias_string + a + 1);
			break;
		}

	for (b = 0; data->alias_list[b]; b++)
		if (str_compare(buffer, data->alias_list[b], a) &&
			data->alias_list[b][a] == '=')
		{
			free(data->alias_list[b]);
			break;
		}

	if (temp)
	{
		append_str(buffer, "=");
		append_str(buffer, temp);
		data->alias_list[b] = str_dup(buffer);
	}
	else
		data->alias_list[b] = str_dup(alias_string);
	return (0);
}
