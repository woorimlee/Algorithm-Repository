#include <iostream>
#include <stack>

using namespace std;

int main() {
	string k;
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> k;
		stack <char> s;
		stack <char> c;
		for (int i = 0; i < k.size(); i++)
		{
			if (k[i] == '(') {
				c.push(k[i]);
			}
			else if (k[i] == ')') {
				s.push(k[i]);
				if (c.empty()) {
					break;
				}
				c.pop();
				s.pop();
			}
		}
		if (c.empty() && s.empty()) {
			cout << "YES" << '\n';
		}
		else if (!c.empty() || !s.empty()) {
			cout << "NO" << '\n';
		}
	}
}