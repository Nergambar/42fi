#ifndef BASE_HPP
#define BASE_HPP

class A;
class B;
class C;

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdint.h>

class Base
{
	public:
		virtual ~Base(){}
};

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif