#include "vector.h"

#include <iostream>
#include <stdexcept>
#include <ctime>
#include <cstdlib>

int main()
{
	Vector v1, v2(10), v3(10, 4);
	v1.Print();
	v2.Print();
	v3.Print();
	std::cout << std::endl;

	// random
	srand((unsigned int)time(0));
	
	const int size = 3;
	int n[size] = { 0 };
	
	// array of vectors
	Vector* vs[size] = { &v1, &v2, &v3 };

	// let's put random number to vectors
	for (int i = 0; i < size; ++i)
	{
		n[i] = rand() % (15 + 5 * i);
		for (int j = 0; j < n[i]; j++) 
		{
			vs[i]->PushBack(rand() % n[i] - n[i] / 2);
		}
	}

	// check
	v1.Print();
	v2.Print();
	v3.Print();
	std::cout << std::endl;

	try
	{
		v1.At(10) = 100;
		v1.Print();
	}
	catch (std::out_of_range & out)
	{
		std::cerr << "wrong index 10" << out.what() << std::endl;
	}

	
	int nn = rand() % 2;
	Vector v4;
	try
	{
		for (int i = 0; i < nn; i++)
		{
			v4.PushBack(5);
		}
		std::cout << v4.PopBack() << std::endl;
	}
	catch (std::underflow_error & und)
	{
		std::cerr << "vector is empty" << und.what() << std::endl;
	}

	return 0;
}