#include <iostream>

using namespace std;

int main()
{
	int N, M;
	int card[101];
	cin >> N >> M;
	//M�� ������ ���� ������ ����
	int ans = 0;
	for (int i = 0; i < N; i++) {
		//ī�� �Է�
		cin >> card[i];
	}

	//3�� �������� ��� ������ ��츦 �˻��� ����.
	for (int i = 0; i < N - 2; i++)	{
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++)	{
				//�� ī���� ���� M������ ���ÿ�, ������ ����� M�� �ִ�� ������ ī���� ���� ���� ī���� �պ��� ������ 
				if (card[i] + card[j] + card[k] <= M &&  ans < card[i] + card[j] + card[k])
				{
					//�� ����
					ans = card[i] + card[j] + card[k];
				}
			}
		}
	}
	//next_permutation���ε� Ǯ �� ������.
	cout << ans;
}