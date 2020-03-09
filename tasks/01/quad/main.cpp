
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>
#include <cmath>

struct Data {
    int* data;
    int len;
};

int *getElem(Data *pData, int i) {
    int* pInt = &(pData->data[i]);
    return pInt;
}

void init(Data &d, int size)
{
    srand((unsigned int)time(0));
    d.data = new int[size];

    for (int i = 0; i < size; ++i)
    {
        *getElem(&d, i) = rand() % (size * 2 + 1);
    }
}

void now(int &day, int &mon, int &year)
{
	time_t ptr = time(0);
	tm *ptm = localtime(&ptr);

	day = ptm->tm_mday;
	mon = ptm->tm_mon + 1;
	year = ptm->tm_year + 1900;
}

void printArray(const int* data, const int& len)
{
    for (int i = 0; i < len; ++i)
    {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int* primes(int n, int& len)
{
	int* data = new int[n];
	data[len++] = 2;

	for (int candidate = 3; candidate <= n; candidate++) {
		bool isPrime = true;
		for (int divisor = 2; divisor <= std::sqrt(candidate); divisor++) {
			if (candidate % divisor == 0) {
				isPrime = false;
                break;
			}
		}
		if (isPrime) {
			data[len++] = candidate;
		}
	}
	return data;
}

int & f1()
{
    static int k = 0;

    k = k * k;

    std::cout << "previous k=" << k << std::endl;

    return k;
}

void f2()
{
    int a = 0;

    std::cout << "Please, enter a number: ";
    std::cin >> a;

    f1() = a;
}

int main()
{
    // task 01
	int day, mon, year;
	now(day, mon, year);
	std::cout << day << " " << mon << " " << year << std::endl << std::endl;

	// task 02
	int len = 0;
	int* data = primes(100, len);
	printArray(data, len);
    std::cout << std::endl;

	// task 03
	Data dataStr;
    init(dataStr, 5);
    printArray(dataStr.data, 5);
    int* pInt = getElem(&dataStr, 1);
    *pInt = 100;
    printArray(dataStr.data, 5);

    // task 04
    f2();
    f2();
    f2();

	return 0;
}

