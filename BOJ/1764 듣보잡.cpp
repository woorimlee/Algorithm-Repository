#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main(void) {
	int n;
	cin >> n;

	stack<int> st;
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
				cout << st.top() << endl;
				st.pop();
			}
			else { //st.empty()가 참인 경우겠지
				cout << "-1" << endl;
			}
		}

		else if (str == "size") {
			cout << st.size() << endl;
		}

		else if (str == "empty") {
			if (st.empty()) {
				//st.empty() 스택이 비어있을 때 1을 반환하고
				//아니면 0을 반환해.
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}

		else if (str == "top") {
			//st.top();
			if (st.empty()) {
				cout << "-1" << endl;
			}
			else {
				cout << st.top() << endl;
			}
		}
	}
	return 0;
}