#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "Data.hpp"

class Data;

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		Serializer &operator=(const Serializer &cpy);
		virtual ~Serializer() = 0;

		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
};

#endif