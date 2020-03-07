#include <iostream>
using namespace std;

int main() {
    char * MyArr;
    int i;

    cout << "Enter a number: " << endl;
    cin >> i;

    MyArr = new char[i];

    delete [] MyArr;

}
