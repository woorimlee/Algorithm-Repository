#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int m,q, n;
string str_q[501];
int word_idx[101]; //�з��Ⱑ �ν��� ������ �ܾ��� ��ȣ(��ġ)�� ������ �迭
double B[501];
double T[501][501];
double M[501][501];
double cache[102][502];
int choice[102][502];

//Q[segment] ���ĸ� ä���� ���� �� �ִ� �ִ� g() ���� �α� ���� ��ȯ.
//Q[segment - 1] == previousMatch
double recognize(int segment, int previousMatch) {
	if (segment == n)
		return 0; //0.0���� �ϸ� ����. ��..?
	
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0)
		return ret;

	ret = -1e200;
	int& choose = choice[segment][previousMatch];
	for (int thisMatch = 1; thisMatch <= m; thisMatch++) {
		double candidate = T[previousMatch][thisMatch] + M[thisMatch][word_idx[segment]] + recognize(segment + 1, thisMatch);
		if (ret < candidate) {
			ret = candidate;
			choose = thisMatch;
		}
	}
	return ret;
}

void reconstruct(int seg, int pre) {
	if (seg == n)
		return;
	
	int choose = choice[seg][pre];
	cout << str_q[choose] << " ";
	reconstruct(seg + 1, choose);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//�ʱ�ȭ
	cin >> m >> q;
	//���� �Է�
	for (int i = 1; i <= m; i++)
		cin >> str_q[i];
	
	//B �Է�
	for (int i = 1; i <= m; i++) {
		cin >> B[i];
		B[i] = log(B[i]);
	}

	//T �Է�
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (i == 0)
				T[i][j] = B[j];

			else {
				cin >> T[i][j];

				T[i][j] = log(T[i][j]);
			}
		}
	}

	//M �Է�
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> M[i][j];
			M[i][j] = log(M[i][j]);
		}
	}

	//q ���� �з���� �ν��� ������ �־���
	while (q--) {
		cin >> n;
		fill(&cache[0][0], &cache[101][502], 1.0);
		for (int i = 0; i < n; i++) {
			string temp;
			cin >> temp;
			for (int j = 1; j <= m; j++) {
				if (temp == str_q[j]) {
					word_idx[i] = j; //i��° ���ڰ� ���� ���� �� ��° �����ΰ�
					break;
				}
			}
		}
		recognize(0, 0);
		reconstruct(0, 0);
		cout << "\n";
	}

	return 0;
}
