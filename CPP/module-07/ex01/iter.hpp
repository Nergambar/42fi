#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T *s, int len, F function)
{
	int i = 0;
	while (i < len)
	{
		function(s[i]);
		i++;
	}
}

#endif