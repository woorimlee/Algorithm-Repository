#include <iostream>
#include <string>
#include <queue>

using namespace std;

//1. �Ҽ� ã��
//2. ���ϴ� ���ڷ� �����ϴµ� �ּ� �� �ܰ谡 �ʿ����� ã�� ���̴�, ���� ���¿��� ���� �ϳ��� �ٲ㼭 ���� �� �ִ� 
//   1) �Ҽ��̰�, 2) 1000 �̻��� ���̸�, 3) ������ �˻����� ���� ���� ��� ť�� �־�θ�, ������� �����ϴµ� �ɸ��� ����� 1�̶�� �����صд�.
//ex) 1033 -> ���� �� �ڸ��� �ٲ㼭 ���� �� �ִ� 1) �Ҽ��̰�, 2) 1000 �̻��� ���̸�, 3) ������ �˻����� ���� ���ڰ� �� 5����, ��� ť�� �־��ٰ� ����.
//    ť�� size�� ���� 5�̸�, �� ���ڿ� �����ϴµ� �ɸ��� ����� 1.
//    ���� ť�� ����ִ� 5���� ���ڸ� �ٽ� ���� �� �ڸ��� �ٲٰ� 1) ~ 3) ������ ������ �����ϴ� ���ڸ� ť�� ������ ������� �ɸ��� ����� +1 �Ѵ�.
//    5���� ���ڸ� ��� �˻��ϰ� �� �� ť�� ���� ������ �˻� ������, 1033���� �� ������ �����ϴµ� ����� 2�� ����.
//    �̷������� �����ϸ� ���ϴ� ���ڿ� ���޽� ����� ���.
//���� ���� �������� ���α׷��� �� ���̱� ������ Queue�� BFS ������ ����� ���̴�.

bool decimal[10000] = { false, };

int change(int num, int index, int x) {
	if (index == 0 && x == 0) {
		return num;
	}
	string s = to_string(num);
	s[index] = x + '0';
	return stoi(s);
}

int main(void) {

	int T, current, goal;
	cin >> T;

	//1. �Ҽ��� ã�Ƽ� bool �迭�� ����صδ� ����.
	//true �� ��� �Ҽ���.
	for (int i = 2; i*i < 10000; i++) {
		if (decimal[i] == false) {
			for (int j = i * i; j < 10000; j += i) {
				decimal[j] = true;
			}
		}
	}

	while (T--) {
		bool flag = false;
		queue <int> q;
		cin >> current >> goal;
		int check[10000] = { 0, };

		if (current == goal) {
			cout << 0 << endl;
			continue;
		}

		//BFS ����.
		q.push(current);
		while (!q.empty()) {
			if (flag == true) {
				break;
			}
			int now = q.front(); q.pop();
			
			//��, ��, ��, õ�� �� �� �ڸ��� �ٲ� ��(int i = 0 ~ 3)
			for (int i = 0; i < 4; i++) {
				if (flag == true) {
					break;
				}
				//�� �ڸ������� �ٲ� �� �ִ� ���� ���� 0 ~ 9. (int j = 0 ~ 9)
				for (int j = 0; j <= 9; j++) {
					//���� �˻��Ϸ��� ��(now)���� i�� �ش��ϴ� �ڸ����� j ���ڷ� �ٲ㼭 1) ~ 3)���� ������ �����ϴ��� �˻��Ѵ�.
					int next = change(now, i, j);
					if (next >= 1000 && !decimal[next] && check[next] == 0) { //1000���� ū ���̰�, �Ҽ���, �˻� �� �� ���̸�
						//������ �˻��� ��ǥ�� �Ǵ� ť�� �־�ΰ�.
						q.push(next);
						//�� ���ڱ��� �����ϱ� ���� ��� ���� +1 �صΰ�.
						check[next] = check[now] + 1;
						//���� ������ ���ڶ�� �ٷ� ���� ���.
						if (next == goal) {
							cout << check[now] << endl;
							flag = true;
						}
					}
				}
			}
		}

		//���� ������ ��� �����ص� ���� ������ �ʴ´ٸ�, Impossible ���.
		if (flag == false) {
			cout << "Impossible" << endl;
		}

	}
	return 0;
}