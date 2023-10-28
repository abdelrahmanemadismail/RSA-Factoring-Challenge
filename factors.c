#include <stdio.h>
#include <stdlib.h>

#include <gmp.h>

/**
 * factorize - Factorize an integer into two smaller integers
 * @str_n: The integer to factorize
 */
void factorize(const char *str_n)
{
	mpz_t n, i, j;
	mpz_t quotient, remainder;

	mpz_inits(n, i, j, NULL);
	mpz_set_str(n, str_n, 10);
	mpz_set_ui(i, 2);
	mpz_set_ui(j, 4);
	while (mpz_cmp(j, n) <= 0)
	{
		mpz_inits(quotient, remainder, NULL);
		mpz_fdiv_qr(quotient, remainder, n, i);
		if (mpz_cmp_ui(remainder, 0) == 0)
		{
			gmp_printf("%Zd=%Zd*%Zd\n", n, quotient, i);
			mpz_clears(n, i, quotient, remainder, NULL);
			return;
		}
		mpz_add_ui(i, i, 1);
		mpz_mul(j, i, i);
		mpz_clear(quotient);
		mpz_clear(remainder);
	}
	mpz_clears(n, i, NULL);
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

	if (argc != 2)
		return (1);

	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
		return (1);
	while (fgets(line, sizeof(line), file) != NULL)
	{
		factorize(line);
	}
	fclose(file);
	return (0);
}
