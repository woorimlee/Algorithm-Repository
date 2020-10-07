#include <iostream>
#include <vector>
#include <map>
using namespace std;

//���� ����
int N;
//�� ����
vector <int> chu_list;
//Ȯ���ϰ��� �ϴ� ������ ����
int M;
//���� ����
vector <int> gu_list;
//������ ���� ���� ������ ��
map <pair<int, int>, bool> ans_list;


void scales(int cur, int now_weight) { //cur == current
	// ���Ը� ���� �� �ִ� ����� �� ����
	//1. ���� + �� == ��
	//2. ���� == ��
	if (ans_list[{cur, now_weight}]) {
		return;
	}
	
	ans_list[{cur, now_weight}] = true;

	if (cur >= N) {
		return;
	}
	//1.�� ��� ���� ����
	//2.�� ��� ���ϱ� ����
	//�� �� : ���� �� �� ����
	scales(cur + 1, now_weight + chu_list[cur]);
	scales(cur + 1, abs(now_weight - chu_list[cur]));
	scales(cur + 1, now_weight);
}

int main() {
	
	//�Է�
	cin >> N;
	int temp;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		chu_list.push_back(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> temp;
		gu_list.push_back(temp);
	}

	//���� �������� Ȯ��s
	scales(0, 0);

	//���
	for (int i = 0; i < M; i++) {
		if (ans_list[{N, gu_list[i]}]) {
			cout << "Y ";
		}
		else cout << "N ";
	}
	return 0;
}