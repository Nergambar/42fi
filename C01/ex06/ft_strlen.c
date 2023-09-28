int ft_strlen(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

/*int	main(void)
{
	char *str;
	
	str = "suh-lut!";
	printf("%d", ft_strlen(str));
}*/
