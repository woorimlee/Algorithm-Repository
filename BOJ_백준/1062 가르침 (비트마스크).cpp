#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int S[51];

//alpha = 현재 배우려는 문자. b부터 시작
//learn = 지금까지 배운 단어
int max_read(int alpha, int learn) { //배운 단어의 조합으로 최대 몇 개의 글자를 읽을 수 있는지 return


	/*cout << "현재 배울 단어 : " << alpha << " " << (char)(alpha + 'a') << "\n지금까지 배운 단어 : ";
	for (int i = 0; i < 26; i++) {
		if (learn & (1 << i))
			cout << (char)(i + 'a') << " ";
	}cout << "\n 총 : " << __builtin_popcount(learn) << "\n\n";*/

	//배울 수 있는 크기만큼 배우면
	if (__builtin_popcount(learn) >= K || alpha >= 26) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if ((S[i] & learn) == S[i]) //배운 단어의 조합과 검사할 단어의 and 연산이 검사할 단어면
				cnt++; //내가 배운 단어 내에서 읽을 수 있는 단어
		}
		return cnt;
	}

	int ret = 0, offset = 0;
	while ((learn & (1 << (alpha + offset))) != 0) {
		offset++;
	}
	//그 단어를 배운 경우, 안 배운 경우 두 가지 경우에서 max 값을 찾음
	ret = max(max_read(alpha + offset + 1, learn | (1 << (alpha + offset))), max_read(alpha + offset + 1, learn));



	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	if (K < 5) {
		cout << 0;
		return 0;
	}

	string s;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			S[i] |= (1 << s[j] - 'a');
		}

	}
	int base = 0;
	int default_string[5] = { 'a' - 'a', 'n' - 'a', 't' - 'a', 'i' - 'a', 'c' - 'a' };
	for (int i = 0; i < 5; i++) {
		base |= (1 << default_string[i]);
	}

	cout << max_read(1, base);

	return 0;
}