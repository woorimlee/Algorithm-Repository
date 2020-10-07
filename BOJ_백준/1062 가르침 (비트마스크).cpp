#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, K;
int S[51];

//alpha = ���� ������ ����. b���� ����
//learn = ���ݱ��� ��� �ܾ�
int max_read(int alpha, int learn) { //��� �ܾ��� �������� �ִ� �� ���� ���ڸ� ���� �� �ִ��� return


	/*cout << "���� ��� �ܾ� : " << alpha << " " << (char)(alpha + 'a') << "\n���ݱ��� ��� �ܾ� : ";
	for (int i = 0; i < 26; i++) {
		if (learn & (1 << i))
			cout << (char)(i + 'a') << " ";
	}cout << "\n �� : " << __builtin_popcount(learn) << "\n\n";*/

	//��� �� �ִ� ũ�⸸ŭ ����
	if (__builtin_popcount(learn) >= K || alpha >= 26) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if ((S[i] & learn) == S[i]) //��� �ܾ��� ���հ� �˻��� �ܾ��� and ������ �˻��� �ܾ��
				cnt++; //���� ��� �ܾ� ������ ���� �� �ִ� �ܾ�
		}
		return cnt;
	}

	int ret = 0, offset = 0;
	while ((learn & (1 << (alpha + offset))) != 0) {
		offset++;
	}
	//�� �ܾ ��� ���, �� ��� ��� �� ���� ��쿡�� max ���� ã��
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