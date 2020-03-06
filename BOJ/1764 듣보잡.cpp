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
			else { //st.empty()�� ���� ������
				cout << "-1" << endl;
			}
		}

		else if (str == "size") {
			cout << st.size() << endl;
		}

		else if (str == "empty") {
			if (st.empty()) {
				//st.empty() ������ ������� �� 1�� ��ȯ�ϰ�
				//�ƴϸ� 0�� ��ȯ��.
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