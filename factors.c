#include <stdio.h>
#include <stdlib.h>

/**
 * factorize - Factorize an integer into two smaller integers
 * @n: The integer to factorize
 */
void factorize(long long n)
{
	long long i;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			printf("%lld=%lld*%lld\n", n, n / i, i);
			return;
		}
	}
}
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char *filename, line[256];
	FILE *file;
	long long n;

	if (argc != 2)
		return (1);

	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
		return (1);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		n = atoll(line);
		factorize(n);
	}
	fclose(file);
	return (0);
}
