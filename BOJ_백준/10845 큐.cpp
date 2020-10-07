#include<iostream>
#include<queue>
#include<string>
#define endl "\n"
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;

	queue<int> st;
	string str;

	for (int i = 0; i < n; i++) {
		cin >> str;

		if (str == "push") {
			int num;
			cin >> num;
			st.push(num);
		}

		else if (str == "pop") {
			if (!st.empty()) {
				cout << st.front() << endl;
				st.pop();
			}
			else {
				cout << "-1" << endl;
			}
		}

		else if (str == "size") {
			cout << st.size() << endl;
		}

		else if (str == "empty") {
			if (st.empty()) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}

		else if (str == "front") {
			if (!st.empty()) {
				cout << st.front() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
		
		else if (str == "back") {
			if (!st.empty()) {
				cout << st.back() << endl;
			}
			else {
				cout << "-1" << endl;
			}
		}
	}
	return 0;
}