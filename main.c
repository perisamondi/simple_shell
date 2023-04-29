#include "shell.h"

/**
 * main - is the entry point
 * @argc: is the arg count
 * @argv: arg vec
 * @env: values for env
 * Return: 0
 */

int main(int argc, char *argv[], char *env[])
{
	d_o_p data_struct = {NULL}, *data = &data_struct;
	char *prompt = "";

	process_data(data, argc, argv, env);

	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)

	{
		errno = 2;
		prompt = PROMPT_MSG;
	}

	errno = 0;
	prompter(prompt, data);
	return (0);
}

/**
 * handle_ctrl_c - ..
 * @UNUSED: is the option of the prototype
 */
void handle_ctrl_c(int opr UNUSED)
{
	print("\n");
	print(PROMPT_MSG);
}

/**
 * process_data - load data from structure
 * @data: ..
 * @argv: args
 * @env: environ
 * @argc: args count
 */
void process_data(d_o_p *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->command_name = NULL;
	data->exec_counter = 0;

	if (argc == 1)
		data->file_descriptor = STDIN_FILENO;
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_print(data->program_name);
			_print(": 0: Can't open ");
			_print(argv[1]);
			_print("\n");
			exit(127);
		}
	}
	data->tokens = NULL;
	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (; env[i]; i++)
		{

			data->env[i] = str_dup(env[i]);
		}
	}
	data->env[i] = NULL;
	env = data->env;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}
/**
 * prompter - show prompt
 * @prompt: prompt
 * @data: ..
 */
void prompter(char *prompt, d_o_p *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{

		print(prompt);
		error_code = string_len = _getline(data);
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			free_data(data);
			exit(errno);
		}
		if (string_len >= 1)
		{
			more_alias(data);
			expand_variables(data);
			split_str(data);
			if (data->tokens[0])
			{
				error_code = run_prog(data);
				if (error_code != 0)
					printerror(error_code, data);
			}
			frec_data(data);

		}
	}
}
