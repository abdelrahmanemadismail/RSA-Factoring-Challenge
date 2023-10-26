#include "main.h"

/**
 * factorize - Factorize an integer into two smaller integers
 * @n: The integer to factorize
 */
void factorize(unsigned long n)
{
	unsigned long i;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%lu = %lu * %lu\n", n, i, n / i);
			return;
		}
	}
	printf("%lu = %lu * %u\n", n, n, 1);
}
