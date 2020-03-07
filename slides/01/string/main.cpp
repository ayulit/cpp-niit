#include <iostream>
#include <string>
using namespace std;

int main() {
    string s0 = "abcde";
    string s1 = "fg";
    string s = s0 + s1;
    cout << s << endl;

    s1 = s0; // deep copy
    cout << s1 << endl; // abcde

    s0 = "muhaha";
    cout << s1 << endl; // abcde, because of deep copy

    s0 = s1;
    if (s1 == s0) {
        cout << "Strings are equal" << endl;
    } else {
        cout << "Strings are NOT equal" << endl;
    }

//    getline(cin, s1);
//    cout << s1 << endl;
//    cout << s1.length() << endl;

    int a = s.find("bc", 0);
    cout << a << endl; // 1

}