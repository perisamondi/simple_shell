#include  "shell.h"

int main(int ac, char **ar, char **ev)
{
	if (ac == 1)
		cue(ar, ev);
	return(0);
}
