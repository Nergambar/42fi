# include <unistd.h>
void numbers(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 10);
	}
	else if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
	}
	if (n > 9)
		numbers(n/10);
	write(1, &"0123456789"[n % 10], 1);
}

int main()
{
	numbers(10);
}
