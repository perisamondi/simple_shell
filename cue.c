#include "shell.h"

/**
 * print - function to output chars
 * @ptr: test parameter
 * Return: count int
 */
int print(char *ptr)
{
	return (write(STDOUT_FILENO, ptr, _strlen(ptr)));
}
/**
 * _print - stderr
 * @ptr: test parameteter
 * Return: count output
 */
int _print(char *ptr)
{
	return (write(STDERR_FILENO, ptr, _strlen(ptr)));
}

/**
 * _printerror - ..
 * @data: program's data'
 * @errorcode: error code
 * Return: count ouput
 */
int printerror(int ecode, d_o_p *data)
{
	char string[10] = {'\0'};

	numstr((long) data->exec_counter, string, 10);

	if (ecode == 2 || ecode == 3)
	{
		_print(data->program_name);
		_print(": ");
		_print(string);
		_print(": ");
		_print(data->tokens[0]);
		if (ecode == 2)
			_print(": Illegal number: ");
		else
			_print(": can't cd to ");
		_print(data->tokens[1]);
		_print("\n");
	}
	else if (ecode == 127)
	{
		_print(data->program_name);
		_print(": ");
		_print(string);
		_print(": ");
		_print(data->command_name);
		_print(": not found\n");
	}
	else if (ecode == 126)
	{
		_print(data->program_name);
		_print(": ");
		_print(string);
		_print(": ");
		_print(data->command_name);
		_print(": Permission denied\n");
	}
	return (0);
}

/**
* _getline - function to read input
* @data: program's data
* Return: count output
*/
int _getline(d_o_p *data)
{
	char cuff[BYTES] = {'\0'};
	static char *ac[10] = {NULL};
	static char opera[10] = {'\0'};
	ssize_t bites, x = 0;

	if (!ac[0] || (opera[0] == '&' && errno != 0) ||
		(opera[0] == '|' && errno == 0))
	{
		for (x = 0; ac[x]; x++)
		{
			free(ac[x]);
			ac[x] = NULL;
		}

		bites = read(data->file_descriptor, &cuff, BYTES - 1);
		if (bites == 0)
			return (-1);

		x = 0;
		do {
			ac[x] = str_dup(_strtok(x ? NULL : cuff, "\n;"));
			x = _logic(ac, x, opera);
		} while (ac[x++]);
	}
	data->input_line = ac[0];
	for (x = 0; ac[x]; x++)
	{
		ac[x] = ac[x + 1];
		opera[x] = opera[x + 1];
	}

	return (_strlen(data->input_line));
}


/**
* _logic - function that handles && and || operators
* @ac: command arguments .
* @x: index
* @opera: logical operators
* Return: index of the last command executed
*/
int _logic(char *ac[], int x, char opera[])
{
	char *temp = NULL;
	int h;

	for (h = 0; ac[x] != NULL  && ac[x][h]; h++)
	{
		if (ac[x][h] == '&' && ac[x][h + 1] == '&')
		{

			temp = ac[x];
			ac[x][h] = '\0';
			ac[x] = str_dup(ac[x]);
			ac[x + 1] = str_dup(temp + h + 2);
			x++;
			opera[x] = '&';
			free(temp);
			h = 0;
		}
		if (ac[x][h]== '|' && ac[x][h + 1] == '|')
		{

			temp = ac[x];
			ac[x][h] = '\0';
			ac[x] = str_dup(ac[x]);
			ac[x + 1] = str_dup(temp + h + 2);
			x++;
			opera[x] = '|';
			free(temp);
			h = 0;
		}
	}
	return (x);
}
