#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ȸ�Ǹ� �����Ѵٴ� ������ ������ �κ� ������ ���캸��
// ȸ�Ǹ� �����ϱ� ���� ���� : ���ð��� �������� ������ ȸ�ǰ� �������
// ������ ȸ�ǰ� ���� �� ��Ȳ���� ���� ���� ȸ�Ǹ� ������ִ� ���� : ���� �����ϵ� ���� ������ ȸ�Ǹ� ����
// �� ȸ�� �ð��� ª��, �����ϴ� �ð��� ������ �ٸ� ȸ�ǿ� ���� ȸ�ǰ� �ʰ� �����ٸ� 
// �� ���̸�ŭ(ȸ��a - ȸ��b) �ð��� �����ϰ� ��

int N;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	vector<pair<int, int> > meeting(N);

	for (int i = 0; i < N; i++) {
		cin >> meeting[i].second >> meeting[i].first;
	}
	// ���� ������ �ð��� �������� �������� ���� �� ��ġ�� �ð������� (����� ������) ���� �����ϴ� ���� ���ַ� ����
	sort(meeting.begin(), meeting.end());

	int end_time = meeting[0].first;
	int ans = 1;
	for (int i = 1; i < N; i++)
	{
		if (end_time <= meeting[i].second)
		{
			ans++;
			end_time = meeting[i].first;
		}
	}
	cout << ans;

	return 0;
}
