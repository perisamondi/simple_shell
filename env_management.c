#include "main.h"

/**
 * get_env_var - ..
 * @env_var: var
 * @data: is the program's data
 * Return: ..
 */

char *get_env_var(char *env_var, data_of_program *data)
{
	int a, key_length = 0;

	if (env_var == NULL || data->env == NULL)
		return (NULL);
	key_length = str_len(env_var);

	for (a = 0; data->env[a]; a++)
	{
		if (str_compare(env_var, data->env[a], key_length) &&
		 data->env[a][key_length] == '=')
		{
			return (data->env[a] + key_length + 1);
		}
	}
	return (NULL);
}

/**
 * env_set_key - will overide the current key
 * @key: var
 * @value: is the new value
 * @data: is the program's data
 * Return: 0, 1 or 2
 */

int env_set_key(char *key, char *value, data_of_program *data)
{
	int a, key_length = 0, is_new_key = 1;

	if (key == NULL || value == NULL || data->env == NULL)
		return (1);

	key_length = str_len(key);

	for (a = 0; data->env[a]; a++)
	{
		if (str_compare(key, data->env[a], key_length) &&
		 data->env[a][key_length] == '=')
		{
			is_new_key = 0;
			free(data->env[a]);
			break;
		}
	}

	data->env[a] = str_join(str_dup(key), "=");
	data->env[a] = str_join(data->env[a], value);

	if (is_new_key)
	{
		data->env[a + 1] = NULL;
	}
	return (0);
}

/**
 * env_delete_key - will remove a key
 * @key: will test the par
 * @data: is the program's data
 * Return: 1 or 0
 */
int env_delete_key(char *key, data_of_program *data)

{
	int a, key_length = 0;

	if (key == NULL || data->env == NULL)
		return (0);

	key_length = str_len(key);

	for (a = 0; data->env[a]; a++)
	{
		if (str_compare(key, data->env[a], key_length) &&
		 data->env[a][key_length] == '=')
		{
			free(data->env[a]);

			a++;
			for (; data->env[a]; a++)
			{
				data->env[a - 1] = data->env[a];
			}
			data->env[a - 1] = NULL;
			return (1);
		}
	}
	return (0);
}


/**
 * show_environ - will rep the current env
 * @data: is the program's data
 */

void show_environ(data_of_program *data)
{
	int b;

	for (b = 0; data->env[b]; b++)
	{
		_print(data->env[b]);
		_print("\n");
	}
}