#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


void permutation(string str, string prefix) {
    if (str.length() == 0) {
        cout << prefix << "\n";
    }
    else {
        for (int i = 0; i < str.length(); i++) {
            string rem = str.substr(0, i) + str.substr(i + 1);
            permutation(rem, prefix + str[i]);
        }
    }
}
void permutation(string str) {
    permutation(str, "");
}

int main() {
    permutation("abcd");

	return 0;
}