#include <iostream>

using namespace std;

int N, K;
bool* check;
int** ranking;

void printRanking();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	//�ݸ޴� ȹ�� ���� -> ���޴� -> ���޴� ������ K������ ������ �ϳ��� �о �ǵ�,
	//���޴� �˻��� �� (�̹� �ݸ޴޿����� ������ �̹� �з�����)
	//�ݸ޴� ������ �ڱ⺸�� ���ų� ���� �ֵ��̶��� �񱳸� �� �ʿ䰡 ����.
	//�׿� ���� check �迭�� ����.
	check = new bool[N + 1];
	fill_n(check, N + 1, false);

	ranking = new int* [N + 1];
	for (int i = 1; i <= N; i++) {
		ranking[i] = new int[3];
	}

	int a, b, c, d;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		ranking[a][0] = b;
		ranking[a][1] = c;
		ranking[a][2] = d;
	}
	//printRanking();

	int rank = 1;
	int k_medal;
	//�� -> �� -> �� �˻縦 ���� �� �� for ���� ����
	for (int i = 0; i < 3; i++) {
		k_medal = ranking[K][i];
		//i == 0�϶� �ݸ޴�, ...
		for (int j = 1; j <= N; j++) {
			if (K == j)
				continue;
			//���� K ������ �޴� �������� ���� ���� ������ ���� ����
			if (check[j] == false && k_medal < ranking[j][i]) {
				rank++;
				check[j] = true;
			}
			//���� K ������ �޴� �������� ���� �ִ� ���� �޴޵� �˻��� �ʿ䰡 ����
			else if (check[j] == false && k_medal > ranking[j][i]) {
				check[j] = true;
			}
		}
	}
	cout << rank;

	return 0;
}

void printRanking() {
	for (int i = 1; i <= N; i++) {
		cout << i << ":" << ranking[i][0] << " " << ranking[i][1] << " " << ranking[i][2] << '\n';
	}
}