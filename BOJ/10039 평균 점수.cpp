#include <iostream>
#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

int main()
{

	int T, X=0, Y=0;
	string str;
	cin >> T;
	int k;
	stack <char> p;
	for (int i = 0; i < T; i++) {
		k = 0;
		cin >> str;
		for (int g = 0; g < str.size(); g++) {
			if (str[g] == ')') {
				X++;
			}
			else {
				Y++;
			}
		}

		while (X != 0 && Y != 0) {
			cout << X << " " << Y << endl;
			if (str[k] == ')') {
				if (str[k + 1] == ')') {
					X--;
					Y--;
				}
			}
			continue;
				
			k++;

		}
	if (X == Y) {
		printf("YES");
	}
	else {
		printf("NO");
	}
}
return 0;
}