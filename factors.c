#include <stdio.h>
#include <stdlib.h>

/**
 * atoll128 - Convert a string to a __int128 integer
 * @str: The string to convert
 * Return: The resulting __int128 integer
 */
__int128 atoll128(char *str)
{
	__int128 result = 0;

	while (*str != '\n')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result);
}
/**
 * print128 - Print a __int128 integer
 * @x: The __int128 integer to print
 */
void print128(__int128 x)
{
	if (x == 0)
		return;
	print128(x / 10);
	putchar('0' + (int)(x % 10));
}
/**
 * factorize - Factorize an integer into two smaller integers
 * @n: The integer to factorize
 */
void factorize(__int128 n)
{
	__int128 i;

	for (i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			print128(n);
			putchar('=');
			print128(n / i);
			putchar('*');
			print128(i);
			putchar('\n');
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
	__int128 n;

	if (argc != 2)
		return (1);

	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
		return (1);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		n = atoll128(line);
		factorize(n);
	}
	fclose(file);
	return (0);
}
