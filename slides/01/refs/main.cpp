#include <iostream>
using namespace std;

void fun(const int &ref) {
    cout << ref << endl;
}

int main() {
    int count = 1;
    int &cRef = count; // reference like alias

    cout << &cRef << endl; // address
    cout << cRef << endl;  // value

    ++cRef;
    cout << count << endl;  // 2

    int *p = &cRef; // pointer points to ref


    const int &ciRef = 1;

    short m = 15;
    int n = 5;
    fun(10);
    fun(m);
    fun(n);
}

