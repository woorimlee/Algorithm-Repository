/*
�� ���� �� ���� �� �ٲٴϱ�
�Է¹��� ������ �迭����
�� �࿡ 0�� ������ K���� ���� �͵� ��
���� ���� �Ȱ��� ���¸� ���� �ִ� ���� ���ϸ� ��.

������ �־���. (�������� ����)
����ġ�� ������ K�� ��ŭ ��������.
���� ���� ¦���� Ŭ���ϸ� ����ġ ������ �� ���� �� ������, �̰� �߰��ؾ� ��

���� ����ġ ���� ���
K - 0�� ������ ���� Ȧ���� �׳� ���ϴ°Ű�,
¦���� ����
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int N, M, K;
//ó���� ��Ʈ�� �迭�ߴٰ� �������� ����������
//��Ʈ������ó����
string table[51] = { "" };

int main() {
	cin.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> table[i];
	}
	cin >> K;

	int cnt = 0;
	int same = 1;
	int max = 0;
	for (int i = 0; i < N; i++) {
		//i ���� 0�� ������ ��
		cnt = 0; // 0�� ������ ����
		same = 0; // ���� ������ ���� ������ ����
		for (int j = 0; j < M; j++) {
			if (table[i][j] == '0')
				cnt++;
		}
		//cnt�� k���� �۰ų� ����, k-cnt�� ¦����
		if (cnt <= K && (K - cnt) % 2 == 0) {
			//�ڱ�� �Ȱ��� ������ ���� ã��
			for (int k = i; k < N; k++) {
				if (table[i] == table[k])
					same++;
			}
			max = max < same ? same : max;
		}
		
	}
	cout << max;
	return 0;
}
