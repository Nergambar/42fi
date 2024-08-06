#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		ft_putchar(str[count]);
		count++;
	}
}

/*int		main(void)
{
	char	*str;

	str = "salut";
	ft_putstr(str);
}*/
