#include "shell.h"
/**
 * _strtok - split string into tokens
 * @line: command
 * @delimator: marker
 * Return: result
*/
char *_strtok(char *line, char *delimator)
{
	int j;
	static char *str;
	char *string;

	if (line != NULL)
		str = line;
	for (; *str != '\0'; str++)
	{
		for (j = 0; delimator[j] != '\0'; j++)
		{
			if (*str == delimator[j])
			break;
		}
		if (delimator[j] == '\0')
			break;
	}
	string  = str;
	if (*string == '\0')
		return (NULL);
	for (; *str != '\0'; str++)
	{
		for (j = 0; delimator[j] != '\0'; j++)
		{
			if (*str == delimator[j])
			{
				*str = '\0';
				str++;
				return (string);
			}
		}
	}
	return (string);
}

/**
 * split_str - ..
 * @data: the program's data
 * Return: different commands
 */
void split_str(d_o_p *data)
{
	char *space= " \t";
	int i, b, sum = 2, length;

	length = _strlen(data->input_line);
	if (length)
	{
		if (data->input_line[length - 1] == '\n')
			data->input_line[length - 1] = '\0';
	}

	for (i = 0; data->input_line[i]; i++)
	{
		for (b = 0; space[b]; b++)
		{
			if (data->input_line[i] == space[b])
				sum++;
		}
	}

	data->tokens = malloc(sum* sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}
	i = 0;
	data->tokens[i] = str_dup(_strtok(data->input_line, space));
	data->command_name = str_dup(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = str_dup(_strtok(NULL, space));
	}
}
/**
 * strlen - function calculate sthe length of a string 
 * @str: poiter to string
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (0);

	while (str[len++] != '\0')
	{
	}
	return (--len);
}
/**
 * str_dup - duplicates string 
 * @str: string to be copied 
 * Return: pointer to the array
 */
char *str_dup(char *str)
{
	char *copy;
	int len, n;

	if (str == NULL)
		return (NULL);

	len = _strlen(str) + 1;

	copy = malloc(sizeof(char) * len);

	if (copy == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (n = 0; n < len ; n++)
	{
		copy[n] = str[n];
	}

	return (copy);
}
/**
 * str_comp - function compare two strings
 * @str1: string 1
 * @str2: string 2
 * @number: parameter
 * Return: 1 or 0
 */
int str_comp(char *str1, char *str2, int number)
{
	int i;

	if (str1 == NULL && str2 == NULL)
		return (1);

	if (str1 == NULL || str2 == NULL)
		return (0);

	if (number == 0)
	{
		if (_strlen(str1) != _strlen(str2))
			return (0);
		for (i = 0; str1[i]; i++)
		{
			if (str1[i] != str2[i])
				return (0);
		}
		return (1);
	}
	else
	{
		for (i = 0; i < number ; i++)
		{
			if (str1[i] != str2[i])
			return (0);
		}
		return (1);
	}
}
/**
 * str_join - joins 2 str
 * @str1: par 1
 * @str2: par 2
 * Return: pointer to the string
 */
char *str_join(char *str1, char *str2)
{
	char *result;
	int length1 = 0, length2 = 0;

	if (str1 == NULL)
		str1 = "";
	length1 = _strlen(str1);

	if (str2 == NULL)
		str2 = "";
	length2 = _strlen(str2);

	result = malloc(sizeof(char) * (length1 + length2 + 1));
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}

	for (length1 = 0; str1[length1] != '\0'; length1++)
		result[length1] = str1[length1];
	free(str1);

	for (length2 = 0; str2[length2] != '\0'; length2++)
	{
		result[length1] = str2[length2];
		length1++;
	}

	result[length1] = '\0';
	return (result);
}
/**
 * str_rev - reverses a string
 * @str: test par
 */
void str_rev(char *str)
{

	int i = 0, length = _strlen(str) - 1;
	char hold;

	while (i < length)
	{
		hold = str[i];
		str[i++] = str[length];
		str[length--] = hold;
	}
}
