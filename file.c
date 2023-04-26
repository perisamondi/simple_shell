#include "shell.h"
/**
 * file  - checks if the there is a system end. if  so avoid fork calling
 * @cx - string to check
 * Return: append to the required path if true/ Null if false
 */
char *file(char *cx)
{
	DIR *directory = opendir("/bin/");
	struct dirent  *entry;
	char *temp, *pets;

	if (directory == NULL)
		return (NULL);
	entry = readdir(directory);
		while (entry != NULL)
		{
			temp = entry->d_name;
			if (strcmp(temp , cx) == 0)
			{
				pets = strcat("/bin/",cx);
				closedir(directory);
				return(pets);
			}
			entry = readdir(directory);
		}
	closedir(directory);
	return (NULL);
}
