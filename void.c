#include "shell.h"

/**
 * numstr - change number  to string
 * @num: test par
 * @str: output
 * @base: type
 */
void numstr(long num, char *str, int base)
{
	int index = 0, inn = 0;
	long coco = num;
	char ABC[] = {"0123456789abcdef"};

	if (coco== 0)
		str[index++] = '0';

	if (str[0] == '-')
		inn = 1;

	while (coco)
	{
		if (coco < 0)
			str[index++] = ABC[-(coco % base)];
		else
			str[index++] = ABC[coco % base];
		coco /= base;
	}
	if (inn)
		str[index++] = '-';

	str[index] = '\0';
	str_rev(str);
}
int _atoi(char *dwell)
{
	int s = 1;
	unsigned int number = 0;

	while (!('0' <= *dwell && *dwell <= '9') && *dwell != '\0')
	{
		if (*dwell == '-')
			s *= -1;
		if (*dwell == '+')
			s *= +1;
		dwell++;
	}

	while ('0' <= *dwell && *dwell <= '9' && *dwell != '\0')
	{
		number = (number * 10) + (*dwell - '0');
		dwell++;
	}

	return (number * s);
}
/**
 * count - count repetition
 * @str: test par
 * @chars: string with  chars
 * Return: int
 */
int count(char *str, char *chars)
{
	int i = 0, num = 0;

	for (; str[i]; i++)
	{
		if (str[i] == chars[0])
			num++;
	}	return (num);
}
/**
 * frec_data - function to keep the buffers clean
 * @data: ..
 */
void frec_data(d_o_p *data)
{
	if (data->tokens)
		fpointer(data->tokens);
	if (data->input_line)
		free(data->input_line);
	if (data->command_name)
		free(data->command_name);

	data->input_line = NULL;
	data->command_name = NULL;
	data->tokens = NULL;
}

/**
 * free_data - clean all data
 * @data: ..
 */
void free_data(d_o_p *data)
{
	if (data->file_descriptor != 0)
	{
		if (close(data->file_descriptor))
			perror(data->program_name);
	}
	frec_data(data);
	fpointer(data->env);
	fpointer(data->alias_list);
}
/**
 * fpointers_array - ..
 * @array: array of pointers
 */
void fpointer(char **array)
{
	int i;

	if (array != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
