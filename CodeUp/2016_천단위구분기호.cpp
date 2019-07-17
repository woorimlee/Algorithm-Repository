#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int n;
	string str;
	stack <char> st;
	stack <char> answer;
	cin >> n >> str;

	for (int i = 0; i < str.length(); i++) {
		st.push(str[i]);
	}
	int count = 0;
	
	while (!st.empty()) {
		if (count == 3) {
			count = 0;
			answer.push(',');
		}
		answer.push(st.top());
		st.pop();
		count++;
		
	}

	while (!answer.empty()) {
		cout << answer.top();
		answer.pop();
	}

	return 0;
}