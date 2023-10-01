#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(int ac, char **av)
{
	FILE *fptr;
	char *lineptr;
	size_t n = 0;
	char *num;
	unsigned long long i = 1;
	unsigned long long number;
	__ssize_t nread;
	
	char *endptr;

	if (ac != 2)
	{
		fprintf(stderr, "Usage %s <file>\n",av[0]);
		exit(EXIT_FAILURE);
	}
	fptr = fopen(av[1], "r");
	if (fptr == NULL)
	{
		perror("fopen");
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&lineptr, &n, fptr)) != -1)
	{
		num = strtok(lineptr,"\n");
		number = strtoull(num, &endptr,10);
		while (i * i <= number)
		{
			if (number % i == 0)
			{
				printf("%llu = %llu * %llu \n", number, number / i, i);
				break;
			}
			i = i + 1;
		}
	}
	free(lineptr);
	fclose(fptr);
	return (0);
}