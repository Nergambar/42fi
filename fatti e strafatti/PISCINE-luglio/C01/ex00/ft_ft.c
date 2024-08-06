#include <stdio.h>

void	ft_ft(int *nbr)
{
	*nbr = 42;
}

 int	main(void)
{
	int tumareomo;
	int *nbr;
	nbr = &tumareomo;
	ft_ft(nbr);
	printf("%i", *nbr);
}
