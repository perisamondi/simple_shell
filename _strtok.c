#include  "shell.h"
/**
 * _strtok- function that prints '$' first line
 * @cx - pointer to string parameter
 * Return : array of string
 */
char **_strtok(char *cx)
{
	char **cat, *dog;
	int  i , c  = 0;
	
	cat = malloc(8 * sizeof(char *));
	if(cat == NULL)
	{
		printf("Could not allocate space");
	exit(1);
	}
	dog = strtok(cx, " ");
		while(dog != NULL)
		{
			while (dog[c])
			{
				if (dog = '\n')
					dog[c]= '\0';
				c++;
			}
			cat[i]= dog;
			i++;
			c = 0;
			dog = strtok(NULL, " ")
		}
	cat[i] = NULL;
	return (cat);
}
