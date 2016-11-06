#include <stdio.h>

/*########################################################################################
 * primes1.c by Antoine BECK under the MIT Licence (see LICENCE file in repository)
 * a simple is_prime function, printing primes under a limit n and mapping primes under n
 #########################################################################################*/

//Healthy amount of typing paranoïa
#define TERM_WIDTH		(unsigned int)80

#define PRINT_PRIMES_LIMIT	(unsigned int)80000
#define MAP_NOT_PRIME		(char)'.'
#define MAP_PRIME		(char)'#'
#define MAP_ROW			(unsigned int)72

#define MAP_MARGIN		(unsigned int)(TERM_WIDTH-MAP_ROW)/2

int is_prime(unsigned int n)
{
	unsigned int i = 5;

	if (n <= 1 || n % 2 == 0 || n % 3 == 0) //optimize
		return 0;
	else if (n == 3) // yeah ...
		return 1;
	while (i*i < n) //here we go now
	{
		if (n%i == 0 || n % (i + 2) == 0)
			return 0;
		i += 6;
	}
	return 1;
}

int print_primes_under(unsigned int n)
{
	unsigned int i;
	unsigned int primeCount = 0;
	if (n >= PRINT_PRIMES_LIMIT)
		return -1;

	putchar('3');

	for (i = 4; i < n; ++i)
	{
		if (is_prime(i))
		{
			++primeCount;
			printf(", %i", i);
		}
	}

	putchar('\n');
	return primeCount;
}

int map_primes_under(unsigned int n)
{
	unsigned int i, j;
	unsigned int primeCount = 0;
	if (n >= PRINT_PRIMES_LIMIT)
		return -1;

	for (j = 0; j < MAP_MARGIN; ++j)//making it look nice
		putchar(' ');

	for (i = 1; i <= n; ++i) // check every number ...
	{
		if (is_prime(i))
		{
			putchar(MAP_PRIME);
			++primeCount;
		}
		else
			putchar(MAP_NOT_PRIME);

		if (i%MAP_ROW == 0) //yep, next row
		{
			putchar('\n');
			for (j = 0; j < MAP_MARGIN; ++j) //making it look nice again
				putchar(' ');
		}
	}
	return primeCount;
}

void error(char* errstr) //because why not
{
	fprintf(stderr, "%s\n", errstr);
	exit(1);
}

int main()
{
	unsigned int ret;
	int test = 1224;
	printf("________________________________________________________________________________");
	printf("                 Map of all the primes under %i by rows of %i\n", test, MAP_ROW);
	printf("                       \'#\' means we hit a prime number\n");
	printf("________________________________________________________________________________");
	ret = map_primes_under(test);
	if (ret == -1)
		error("(main)map_primes_under failed !!\n");

	putchar('\n');
	printf("________________________________________________________________________________");
	printf("Found %i primes under %i.\n\n", ret, test);
	return 0;
}
