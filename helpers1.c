#include "shell.h"

/**
 * free_recurrent_data - is the function to keep the buffers clean
 * @data: ..
 */

void free_recurrent_data(d_o_p *data)
{
	if (data->tokens)
		free_pointers_array(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_data -will clean all data
 * @data: ..
 */

void free_data(d_o_p *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	free_recurrent_data(data);
	free_pointers_array(data->env);
	free_pointers_array(data->alias_list);
}

/**
 * free_pointers_array - ..
 * @myarray: array of pointers
 */

void free_pointers_array(char **myarray)
{
	int a;

	if (myarray != NULL)
	{
		for (a = 0; myarray[a]; a++)
			free(myarray[a]);

		free(myarray);
		myarray = NULL;
	}
}