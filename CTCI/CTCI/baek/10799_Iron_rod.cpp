#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int answer = 0;
	vector <char> rod;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') rod.push_back(str[i]);
		else if (str[i] == ')') {
			//만약 레이저라면
			if (str[i - 1] == '(') {
				rod.pop_back();
				answer += rod.size();
			}
			//쇠막대기 자투리 하나 남음
			else {
				rod.pop_back();
				answer += 1;
			}
		}
	}

	cout << answer << endl;
	return 0;
}