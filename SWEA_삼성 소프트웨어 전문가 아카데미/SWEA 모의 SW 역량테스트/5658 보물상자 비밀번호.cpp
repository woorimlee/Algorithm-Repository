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

		//각 변에 있는 숫자의 개수
		int numLength = N / 4;
		for (int i = 0; i < numLength; i++) { // 각 변에 숫자있는 개수만큼 for 구문을 돌려야하네..
			for (int j = 0; j < 4; j++) { // str을 네 번씩 자름
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