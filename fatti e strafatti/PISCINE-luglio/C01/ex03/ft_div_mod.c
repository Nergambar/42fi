void ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int main (void)
{
	int a = 9;
	int b = 9;
	int div = 0;
	int mod = 0;
	ft_div_mod(a, b, &div, &mod);
	printf("%d divided by %d, is %d with %d remainder", a, b, div, mod);
}
