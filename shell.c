#include "shell.h"
/**
 * main - performs functiou cue
 * @ac : argument count
 * @ar : argument vector
 * @ev: environment pointer
 * Return : 0 on success
 */
int main(int ac, char **ar ,char **ev)
{
	if (ac == 1)
	{
		cue(ar , ev);
	}
		return (0);
}
