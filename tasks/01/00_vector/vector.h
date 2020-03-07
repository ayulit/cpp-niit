#pragma once

// needed on Mac
#include <cstddef>

class Vector
{
public:
	Vector() : data(nullptr), size(0), capacity(0) {}
	Vector(size_t size);
	Vector(size_t size, int val);
	Vector(const Vector& ref); // copy constructor
	~Vector();
	void Print() const;
	void PushBack(int val);
	int PopBack();
	int At(size_t index) const;
	int& At(size_t index);
	size_t Size() const { return size; }
	size_t Capacity() const { return capacity; }
private:
	int *data;
	size_t size;
	size_t capacity;
};