#include <iostream>
using namespace std;

int main() {
//    int a, b, c;
//    float p;
//    cin >> a >> b >> c >> p;
//
//    cout << a << endl
//         << b << endl
//         << c << endl
//         << p << endl;


//    char str[100];
//    cin.getline(str, 100);
//    cout << str << endl;


    float arr[3] = {1.2, 3.4, 5.6};
    cout.setf(ios::fixed);
    cout.precision(2);
    for (int i = 0; i < 3; ++i) {
        cout.width(6);
        cout << arr[i];
    }
    cout << endl;

}