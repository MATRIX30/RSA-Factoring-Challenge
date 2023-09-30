#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <gmp.h>


int main(int ac, char **av)
{
	char str[500];
	int fd;
	char *num = NULL;
	ssize_t read_count = 0;
	mpz_t number;
	mpz_init(number);


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
	while (num)
	{
		mpz_set_str(number, num, 10);
		gmp_printf("%Zd\n", number);
		num = strtok(NULL, "\n");
	}
	mpz_clear(number);
	printf("Last .. %c\n", str[read_count - 5]);
	printf("finish\n");
	close(fd);
	return (0);

}