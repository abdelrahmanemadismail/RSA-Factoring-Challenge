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
			mpz_clears(n, i, j, quotient, remainder, NULL);
			return;
		}

		mpz_nextprime(i, i);
		mpz_mul(j, i, i);
		mpz_clear(quotient);
		mpz_clear(remainder);
	}
	mpz_set_ui(i, 1);
	gmp_printf("%Zd=%Zd*%Zd\n", n, n, i);
	mpz_clears(n, i, j, NULL);
}
/**
 * pollards_rho - Pollard's Rho Algorithm for factorization
 * @str_n: The integer to factorize
 */
void pollards_rho(const char *str_n)
{
	mpz_t x, y, d, n, f, factor;

	mpz_inits(x, y, d, n, f, factor, NULL);
	mpz_set_ui(x, 2);
	mpz_set_ui(y, 2);
	mpz_set_ui(d, 1);
	mpz_set_str(n, str_n, 10);

	while (mpz_cmp_ui(d, 1) == 0)
	{
		mpz_mul(x, x, x);
		mpz_add_ui(x, x, 1);
		mpz_mod(x, x, n);

		mpz_mul(y, y, y);
		mpz_add_ui(y, y, 1);
		mpz_mod(y, y, n);
		mpz_mul(y, y, y);
		mpz_add_ui(y, y, 1);
		mpz_mod(y, y, n);

		mpz_sub(factor, x, y);
		mpz_abs(factor, factor);
		mpz_gcd(d, factor, n);
	}

	if (mpz_cmp(d, n) != 0)
	{
		mpz_divexact(f, n, d);
		gmp_printf("%Zd=%Zd*%Zd\n", n, f, d);
	}
	else
	{
		mpz_set_ui(f, 1);
		gmp_printf("%Zd=%Zd*%Zd\n", n, n, f);
	}
	mpz_clears(x, y, d, n, f, factor, NULL);
}
/**
 * main - Entry point
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	char *filename, *line = NULL;
	size_t len = 0;
	ssize_t read;
	FILE *file;

	if (argc != 2)
		return (1);

	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
		return (1);

	while ((read = getline(&line, &len, file)) != -1)
	{
		pollards_rho(line);
	}

	fclose(file);
	if (line)
		free(line);
	return (0);
}
