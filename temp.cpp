#include <iostream>
#include <string>
using namespace std;
int main() {
    string s;
    cin >> s;
    for (auto it : s) {
        if ('A' <= it && it <= 'Z')
            cout << char(it - 'A' + 'a');
        else
            cout << it - 'a' + 'A';
    }
    return 0;
}