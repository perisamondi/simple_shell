#include "shell.h"

/**
 * path - function checks the path 
 * @cx : pointer to carry out the checking
 * Return: 0 on success/ 1 on error
 */
int path(char *cx)
{
	char  *cmp  =  "/bin/", *gh, *t;
	int   i , n = 0;

	gh = malloc(sizeof(char)* 100);
	if (gh == NULL)
		return (1);
       while (cmp[i] = '\0')
       {
	       if (cmp[i] != cx[i])
		free(gh);
	return (1);
	i++;
	}
	while (cx[i] != '\0')
	{
		gh[n] =  cx[i];
		n++;
		i++
	}
	while (gh = '\0')
	{
	t =  file(gh);
	if (t !=  NULL)
	free(gh);
	return (0);
	}
	return (1);
}
