#include <iostream>
#include <stdexcept>
#include <exception>
#include <string>

class Vector
{
public:
	Vector() = delete;
	Vector(int sz)
	{
		if (sz < 0 || sz > MAX_SIZE)
			throw std::invalid_argument("Wrong vector size");
		data = new int[size = sz];
	}
	int GetSize()const { return size; }
	int& operator[](int index)
	{
		if (index < 0 || index >= size)
			throw std::out_of_range("Wrong index ");
		return data[index];
	}
	int operator[](int index)const //throw(std::out_of_range)
	{
		/*if (index < 0 || index >= size)
			throw std::out_of_range("Const version Wrong index ");
		return data[index];*/
		Vector *temp = const_cast<Vector*>(this);
		return (*temp)[index];
	}
private:
	int * data;
	int size;
	const static int MAX_SIZE = 100000;
};

std::ostream& operator<<(std::ostream& os, const Vector & v)
{
	for (int i = 0; i < v.GetSize(); ++i)
		os << v[i] << " ";
	return os;
}

std::istream & operator >> (std::istream & is, Vector& v)
{
	for (int i = 0; i < v.GetSize(); ++i)
		is >> v[i];
	return is;
}

int main()
{

	//try
	//{
	//	Vector v1(10), v2(1000), v3(10000);
	//	try
	//	{
	//		std::cin >> v1;
	//		std::cout << v1 << std::endl;
	//		v2[1000] = 15;
	//		std::cout << v2[1000] << std::endl;
	//	}
	//	catch (std::out_of_range r)
	//	{
	//		std::cout << r.what() << std::endl;
	//		throw;
	//	}
	//	catch (...)
	//	{
	//		std::cout << "66 Something else" << std::endl;
	//	}
	//}
	//catch (std::invalid_argument iv)
	//{
	//	std::cout << iv.what() << std::endl;
	//}
	//catch (...)
	//{
	//	std::cout << "75 Something else" << std::endl;
	//}

	Vector * v1 = nullptr, * v2 = nullptr;
	try
	{
		try
		{
			v1 = new Vector(10000000);
		}
		catch (std::invalid_argument)
		{
		}
		try
		{
			v2 = new Vector(1000);
		}
		catch (std::invalid_argument) {}
		if (v1)
		{
			v1[1] = 15;
		}
		throw std::exception();
	}
	catch (std::invalid_argument iv)
	{
		std::cout << iv.what() << std::endl;
	}
	catch (...)
	{
		if (v1)
			delete v1;
		if (v2)
			delete v2;
		std::cout << "75 Something else" << std::endl;
	}
	return 0;
}



