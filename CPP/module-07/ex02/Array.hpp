#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <iostream>
# include <exception>
# include <ctime>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		T* data;
		unsigned int size;

	public:
		Array() : data(NULL), size(0) {}
		Array(unsigned int n);
		Array(const Array &src);
		Array& operator = (const Array &cpy);
		~Array() { delete[] data;}
		T& operator[](unsigned int i);
		size_t  tsize() const;
};

#endif