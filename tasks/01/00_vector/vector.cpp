#include "vector.h"

#include <iostream>
#include <stdexcept>
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
		std::cout << "Empty ";
	}
	else {
		for (size_t i = 0; i < size; ++i)
		{
			std::cout << data[i] << " ";
		}
		std::cout;
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

Vector& Vector::operator = (const Vector& right)
{
	if (this != &right) {
		delete[] data;

		data = new int[capacity = right.capacity];
		size = right.size;

		for (size_t i = 0; i < size; i++)
		{
			data[i] = right[i];
		}
	}
	return *this;
}

// sum values of one vector with another
Vector Vector::operator + (const Vector& right) const
{

	size_t min = size < right.size ? size : right.size;
	size_t max = size > right.size ? size : right.size;

	int j = size < right.size ? 1 : 2;

	Vector res(max);
	res.size = max;

	for (size_t i = 0; i < min; i++)
	{
		res[i] = data[i] + right[i];
	}

	// for inside if better
	if (1 == j)
	{
		AddTail(res, right, min, max);
	}
	else {
		AddTail(res, *this, min, max);
	}

	return res;
}

// private helper
void Vector::AddTail(Vector& to, const Vector& from, int min, int max) const 
{
	for (size_t i = min; i < max; i++)
	{
		to[i] = from[i];
	}
}

Vector& Vector::operator + (int val)
{
	PushBack(val);
	return *this;
}

int& Vector::operator[] (size_t index) 
{
	return At(index);
}

int Vector::operator[] (size_t index) const
{
	return At(index);
}

Vector& Vector::operator++()
{
	for (size_t i = 0; i < size; i++)
	{
		++data[i];
	}
	return *this;
}

Vector Vector::operator++(int)
{
	Vector temp(*this);
	++*this;
	return temp;
}

std::ostream& operator<<(std::ostream& out, const Vector& ref) 
{
	ref.Print();
	return out;
}

std::istream& operator>>(std::istream& in, Vector& ref)
{
	int count = 0;
	std::cout << "Enter amount of elements: " << std::endl;
	in >> count;

	for (size_t i = 0; i < count; i++)
	{
		int val;
		std::cout << "Number " << i + 1 << ": ";
		in >> val;
		ref.PushBack(val);
	}
	return in;
}

bool Vector::operator== (const Vector& right) const
{
	if (size == right.size)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (data[i] != right[i]) {
				return false;
			}
		}
		return true;
	}
	return false;
}

bool Vector::operator != (const Vector& right) const
{
	return !(*this == right);
}























