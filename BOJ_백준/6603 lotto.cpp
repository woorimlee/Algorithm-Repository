#include <iostream>
#include <algorithm>
#include <vector>

//���⿡ �ռ�. ���� ��� �κ��� �ڵ������� �� �� �����ϰ� ����ŵ� �˴ϴ�. 
//���� �׳� ����ϰ� �����ϱ� ���ؼ� answer ���� �ϳ��� �� �����߽��ϴ�.

//K�� �Է� �ް�, K ũ�� ��ŭ ���� S�� ���Ե� ���� �Է� ���� ��.
//1. K�� 7�� ���, 7���� ���� �� 6���� ��� �ζ� ��ȣ�� ������ ���̴�
//   ũ�Ⱑ 7�� bool �迭���� �ϳ��� false, �������� true�� �����
//   �� �迭�� ��� ���� ������ ���Ѵ�.
//2. ���ĵ� ���·� ����� �ؾ��Ѵ�.

using namespace std;
int S[13];
bool check_permutation[13];
vector <vector <int> > answer;
vector <int> vec;

int main(void) {
	int K;

	while (cin >> K) {
		//cin >> K�� cin���� ���� ���� �о K�� ���� �ǵ� 
		//K�� �ڷ����� ���� �ʴ� �Է��� �����ų�, EOF, ���� ���� ��Ȳ�� ���� flase��.
		//while�ȿ� �־������ν� ��Ȯ�� �Է��� ������ �� ��� while���� �����Ŷ�� ����.
		
		if (K == 0) break;
		for (int i = 0; i < K; i++) {
			cin >> S[i];
		}

		//1. �κ�
		for (int i = 0; i < K-6; i++) {
			check_permutation[i] = false;
		}
		for (int i = K-6; i < K; i++) {
			check_permutation[i] = true;
		}
		do {
			for (int i = 0; i < K; i++) {
				if (check_permutation[i] == true) {
					vec.push_back(S[i]);
				}
			}
			answer.push_back(vec);
			vec.clear();
		} while (next_permutation(check_permutation, check_permutation+K));

		//2. �κ�
		sort(answer.begin(), answer.end());
		for (auto it : answer) {
			for (int i = 0; i < it.size(); i++) {
				cout << it[i] << " ";
			}
			cout << endl;
		}
		answer.clear();
		cout << endl;
	}

	return 0;
}