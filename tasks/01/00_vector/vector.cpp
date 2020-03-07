#include "vector.h"

#include <iostream>
#include <stdexcept>

Vector::Vector(size_t s) : capacity(s), size(0)
{
	data = new int[capacity];
}

Vector::Vector(size_t s, int val) : capacity(s), size(s)
{
	data = new int[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		data[i] = val;
	}
}

Vector::Vector(const Vector& ref) : capacity(ref.capacity), size(ref.size)
{
	data = new int[capacity];
	for (size_t i = 0; i < size; ++i)
	{
		data[i] = ref.data[i];
	}
}

Vector::~Vector() 
{
	delete [] data;
}

void Vector::Print() const
{
	if (size == 0) {
		std::cout << "Empty" << std::endl;
	}
	else {
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout << std::endl;
	}
}

void Vector::PushBack(int val)
{
	if (size == capacity)
	{
		// vector is full, need to be extended

		// used temp
		int *temp = new int[capacity = capacity == 0 ? 1 : capacity * 2];
		for (size_t i = 0; i < size; ++i)
		{
			temp[i] = data[i];
		}

		delete[] data;
		data = temp;
	}

	// pushBack
	data[size++] = val;
}

int Vector::PopBack()
{
	// if vector is empty
	if (size == 0) 
	{
		// standard underflow exception
		throw std::underflow_error("");
	}
	return data[--size];
}

int Vector::At(size_t index) const
{
	/*

	// no element
	if (index >= size) 
	{
		throw std::out_of_range("");
	}
	return data[index];

	*/

	Vector* temp = (Vector*)(this);
	return temp->At(index);
}

// user can edit values
int& Vector::At(size_t index)
{
	// no element
	if (index >= size)
	{
		throw std::out_of_range("");
	}
	return data[index];
}





























