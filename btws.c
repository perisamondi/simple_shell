#include "shell.h"

/**
 * expand_variables - ..
 * @data: pointer pointing to the program's data
 */
void expand_variables(d_o_p *data)
{
	int a, b;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;
	append_str(line, data->input_line);
	for (a = 0; line[b]; b++)
		if (line[a] == '#')
			line[a--] = '\0';
		else if (line[a] == '$' && line[a + 1] == '?')
		{
			line[a] = '\0';
			num_to_str(errno, expansion, 10);
			append_str(line, expansion);
			append_str(line, data->input_line + a + 2);
		}
		else if (line[a] == '$' && line[a + 1] == '$')
		{
			line[a] = '\0';
			num_to_str(getpid(), expansion, 10);
			append_str(line, expansion);
			append_str(line, data->input_line + a + 2);
		}
		else if (line[a] == '$' && (line[a + 1] == ' ' || line[a + 1] == '\0'))
			continue;
		else if (line[a] == '$')
		{
			for (b = 1; line[a + b] && line[a + b] != ' '; b++)
				expansion[b - 1] = line[a + b];
			temp = get_env_var(expansion, data);
			line[a] = '\0', expansion[0] = '\0';
			append_str(expansion, line + a + b);
			temp ? append_str(line, temp) : 1;
			append_str(line, expansion);
		}
	if (!str_compare(data->input_line, line, 0))
	{
		free(data->input_line);
		data->input_line = str_dup(line);
	}
}

/**
 * more_alias - ..
 * @data: program's data
 */
void more_alias(d_o_p *data)
{
	int a, b, was_expanded = 0;
	char line[BUFFER_SIZE] = {0}, expansion[BUFFER_SIZE] = {'\0'}, *temp;

	if (data->input_line == NULL)
		return;

	append_str(line, data->input_line);

	for (a = 0; line[a]; a++)
	{
		for (b = 0; line[a + b] && line[a + b] != ' '; b++)
			expansion[b] = line[a + b];
		expansion[b] = '\0';

		temp = retrieve_alias(data, expansion);
		if (temp)
		{
			expansion[0] = '\0';
			append_str(expansion, line + a + b);
			line[a] = '\0';
			append_str(line, temp);
			line[str_len(line)] = '\0';
			append_str(line, expansion);
			was_expanded = 1;
		}
		break;
	}
	if (was_expanded)
	{
		free(data->input_line);
		data->input_line = str_dup(line);
	}
}

/**
 * append_str - will append a string at end of the buffer
 * @buffer: is the buffer
 * @str: value
 * Return: 0
 */
int append_str(char *buffer, char *str)
{
	int length, a;

	length = str_len(buffer);
	for (a = 0; str[a]; a++)
	{
		buffer[length + a] = str[a];
	}
	buffer[length + a] = '\0';
	return (length + a);
}
