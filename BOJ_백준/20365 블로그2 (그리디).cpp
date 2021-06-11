#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int N;
string blog;

int main() {
	cin >> N >> blog;

	// �Ͽ��� ����ȭ ��ĥ ����� �м��غ���
	// �� �� �� ���� �κ� ���� ���� �ɷ� �� �� �� ĥ�ϰ�
	// �������� ���� ������ ĥ��
	
	unordered_map <char, int> cnt;
	char c = blog[0];
	for (int i = 1; i < blog.size(); i++) 
		if (c != blog[i]) {
			cnt[c]++;
			c = blog[i];
		}
	cnt[c]++;

	int ans = 1 + min(cnt['B'], cnt['R']);
	cout << ans;

	return 0;
}