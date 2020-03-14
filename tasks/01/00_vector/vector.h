#pragma once
#include <iostream>

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

	Vector& operator= (const Vector& right);
	Vector operator+ (const Vector& right) const;
	Vector& operator+ (int val);
	int& operator[] (size_t index);
	int operator[] (size_t index) const;
	Vector& operator++();
	Vector operator++(int);

	bool operator== (const Vector& right) const;
	bool operator!= (const Vector& right) const;
private:
	int *data;
	size_t size;     // content
	size_t capacity; // possibilities

	// helper
	void AddTail(Vector& to, const Vector& from, int min, int max) const;
};

std::ostream& operator<<(std::ostream& out, const Vector& ref);
std::istream& operator>>(std::istream& in, Vector& ref);