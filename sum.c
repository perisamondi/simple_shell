#include <stdio.h>

/**
 * add -  sums two int variables
 * @z; sum of x + y
 * Return: 0 on sucess
 */
int add(void)
{
int x, y, z = 0;
printf("Enter number");
scanf("%d", &y);

for  (x = 1; x <= y; x++)
{
z += x;
}
printf("%d/n", z);
return (0);
}
