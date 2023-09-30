#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <gmp.h>
#include <math.h>

int main(int ac, char **av)
{
	char str[500];
	int fd;
	char *num = NULL;
	ssize_t read_count = 0;
	mpz_t number;
	mpz_t root, i;

	mpz_init(number);
	mpz_init(root);
	mpZ_init(i);
	



	if (ac != 2)
	{
		printf("Usage: factors <file>");
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error occured while reading the file\n");
		exit(1);
	}
	read_count = read(fd,str, 200);
	if (read_count == -1)
	{
		printf("they was an error reading from file");
		exit(EXIT_FAILURE);
	}

	num = strtok(str, "\n");
	unsigned long long int j = 2;
	while (num)
	{
		
		mpz_set_str(number, num, 10);
		mpz_sqrt(root,number);
		while(i <= root)
		{
			printf("%llu",i);
			j = j + 1;
		}

		gmp_printf("root --%Zd\n",root);
		gmp_printf("%Zd\n", number);
		num = strtok(NULL, "\n");
		
	}
	mpz_clear(root);
	mpz_clear(number);
	printf("finish\n");
	close(fd);
	return (0);

}