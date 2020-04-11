#include <iostream>

class A {
public:
    void f(long n)
    {
        std::cout << "f(long)" << std::endl;
    }
private:
    void f(short n)
    {
        std::cout << "f(short)" << std::endl;
    }
};

int main()
{
    A a;
    a.f(5l);
}