#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int N; 
	cin >> N;
	getchar();
	for (int i = 0; i < N; i++) {
		string s; 
		getline(cin, s);

		int index = 0;
		stack <string> word;
		while (1) {
			int space = s.find(' ', index);
			if (space == -1) {
				break;
			}
			word.push(s.substr(index, space - index));
			index = space + 1;
		}
		word.push(s.substr(index)); //남은거 다 가져옴

		printf("Case #%d: ", i + 1);
		while (!word.empty()) {
			cout << word.top() << " ";
			word.pop();
		}
		cout << "\n";
	}
	return 0;
}