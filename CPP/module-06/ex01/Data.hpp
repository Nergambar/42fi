#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iostream>
#include <stdint.h>

class Data
{
	private:
		std::string str;
		int num;

	public:
		Data();
		Data(const Data &src);
		Data(std::string str, int num);
		Data &operator = (const Data &cpy);
		~Data();
		std::string getStr();
		int getNum();
	};


#endif