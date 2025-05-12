#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= this->size)
		throw std::exception();
	return data[i];
}

template <typename T>
// int* arr = new int[5](); // All elements initialized to 0
// int* arr2 = new int[5];  // Elements contain garbage values
Array<T>::Array(unsigned int n) : size(n)
{
	data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array &src) : size(src.size)
{
	data = new T[size];
	for (unsigned int i = 0; i < src.size; i++)
		data[i] = src.data[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &cpy)
{
	if (this != &cpy)
	{
		delete[] data;
		data = new T[cpy.size];
		size = cpy.size;
		for (unsigned int i = 0; i < cpy.size; i++)
			data[i] = cpy.data[i];
	}
	return *this;
}

template <typename T>
size_t Array<T>::tsize() const
{
	return this->size;
}

#endif