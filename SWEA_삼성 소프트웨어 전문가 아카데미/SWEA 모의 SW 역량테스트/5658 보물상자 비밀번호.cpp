#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int T, N, K;
string str, temp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		cin >> str;
		set <string, greater<string> > answerSet;
		vector <int> vec;

		//�� ���� �ִ� ������ ����
		int numLength = N / 4;
		for (int i = 0; i < numLength; i++) { // �� ���� �����ִ� ������ŭ for ������ �������ϳ�..
			for (int j = 0; j < 4; j++) { // str�� �� ���� �ڸ�
				answerSet.insert(str.substr(j*numLength, numLength));
			}
			temp = str.substr(1, str.size() - 1) + str[0];
			str = temp;
		}

		for (auto it : answerSet) {
			vec.push_back(stoi(it, nullptr, 16));
		}
		cout << "#" << i << " " << vec[K - 1] << "\n";
	
	}
	return 0;
}