#include "main.h"

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
	unsigned long n;

	if (argc != 2)
		return (1);

	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
		return (1);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		n = strtoul(line, NULL, 10);
		factorize(n);
	}
	fclose(file);
	return (0);
}
