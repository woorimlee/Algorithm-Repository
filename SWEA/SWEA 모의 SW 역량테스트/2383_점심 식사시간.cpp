#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T, N, answer, temp;
struct stairs {
	int x, y, h;
	int count;
	stairs(int x, int y, int h) : x{ x }, y{ y }, h{ h }{};
};

struct people {
	int x, y;
	int distA, distB;
	people(int x, int y) : x{ x }, y{ y }{};
};

vector <people> pe;
vector <stairs> st;


int lunchTime(vector<int> v, int t) {
	if (v.size() == 0) return 0;
	//�����ð� �������� ����
	sort(v.begin(), v.end());

	//��� ��������� Ȯ���ϴ� �迭
	int use[3] = { 0, };

	//������� �ҿ�� �ð�
	int time = v[0];

	while (true) {
		for (int i = 0; i < v.size(); i++) {
			//�̹� ����� �������ٸ� continue
			if (!v[i])continue;

			//�����ð� Ȯ��
			if (v[i] <= time) {

				for (int j = 0; j < 3; j++) {
					//�� ����� �ִ��� Ȯ��
					if (use[j] <= 0) {
						use[j] = t;
						v[i] = 0;
						if (i == v.size() - 1) {
							return time + t;
						}
						break;
					}
				}
			}
		}

		//1�� �����ſ� ���� ó��
		for (int i = 0; i < 3; i++) {
			use[i]--;
		}
		time++;
	}
}

//��� ����� �� ���
void dfs(vector <int> & A, vector <int> &B, int person) {
	if (person >= pe.size()) {
		//��� 1, 2 �̿��ϴ� ����� ���� ����� ���� �� ���������
		answer = min(answer, max(lunchTime(A, st[0].h), lunchTime(B, st[1].h)));
		return;
	}

	//��� ����ŭ
	//cout << answer;
	for (int j = 0; j < 2; j++) {
		if (j == 0) {
			A.push_back(pe[person].distA);
		}
		else
			B.push_back(pe[person].distB);
		//cout << person << " " << j;
		dfs(A, B, person + 1);
		//cout << endl;
		//cout << lunchTime(A, st[0].h) << " ";
		//cout << lunchTime(B, st[1].h) << endl;
		

		if (j == 0)
			A.pop_back();
		else
			B.pop_back();
	}
}

int main() {
	cin >> T;
	int temp;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		//�ʱ�ȭ
		//to do
		pe.clear();
		st.clear();
		answer = 987654321;

		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				cin >> temp;
				if (temp == 1) {
					pe.push_back(people(k, j));
				}
				else if (temp >= 2) {
					st.push_back(stairs(k, j, temp));
				}
			}
		}

		//�ⱸ �Ÿ� ���
		for (int j = 0; j < pe.size(); j++) {
			pe[j].distA = abs(pe[j].x - st[0].x) + abs(pe[j].y - st[0].y);
			pe[j].distB = abs(pe[j].x - st[1].x) + abs(pe[j].y - st[1].y);
			//cout << pe[j].distA << " " << pe[j].distB << endl;
		}

		vector <int> stairA;
		vector <int> stairB;
		//cout << answer;
		dfs(stairA, stairB, 0);
		cout << "#" << i << " " << answer + 1 << "\n";
	}

	return 0;
}