
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <ctime>

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

	for (int i = 3; i <= n; i++)
	{
		bool isPrime = true;
		for (int j = 2; j < i; j++)
		{
			if (i%j == 0) {
				isPrime = false;
			}
		}
		if (isPrime) {			
			data[len++] = i;
		}
	}

	return data;
}

int main()
{
    // task 01
	int day, mon, year;
	now(day, mon, year);
	std::cout << day << " " << mon << " " << year << std::endl;

	// task 02
	int len = 0;
	int* data = primes(10, len);
	printArray(data, len);

	return 0;
}

