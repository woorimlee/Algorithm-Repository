#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T, N, M, K, A, B, answer;

struct customer {
	int tk; // ���� �ð�
	int k; // �� ��ȣ
	int ak = 0; // ���� â�� ��ȣ
	int bk = 0; // ���� â�� ��ȣ
	customer(int tk, int k) : tk{ tk }, k { k } {};
};

void findCustomer(vector <customer> &cus) {
	int time = 0;
	queue <int> reception, repair;
	while (1) {
		//1. ���� �ð��� ������ �ð��� �Ȱ����� ť�� �ֱ�
		for (int i = 0; i < K; i++) {
			if (cus[i].tk == time) {
				reception.push(i);
			}
		}

		//2-1. ���� â�� ��ȣ �ο�
		//���� â�� ����ְ�, reception ť�� ��� �ο� ������

		//2-2. ���� â�� ���� ��� üũ
		//repair�� �߰� reception���� ���� 

		//3-1. ���� â�� ��ȣ �ο�
		//���� â�� ����ְ�, repair ť�� ��� �ο� ������

		//3-2. ���� â�� ���� ��� üũ
		//��� ���� ���� ��� ���� �߰� repair���� ���� 

		//4. ��� �ο��� ���񽺸� �� ������ while ��
	}
}

int main(void) {
	cin >> T;
	int temp;

	for (int i = 1; i <= T; i++) {
		cin >> N, M, K, A, B;
		//�ʱ�ȭ
		vector <int> a; //���� â���� �ð� ����
		vector <int> b; //���� â���� �ð� ����
		vector <customer> cus; //�� ���� ����
		answer = -1;

		for (int j = 0; j < N; j++) {
			cin >> temp;
			a.push_back(temp);
		}
		for (int j = 0; j < N; j++) {
			cin >> temp; 
			b.push_back(temp);
		}
		for (int j = 0; j < K; j++) {
			cin >> temp;
			//���� �ð�, �� ��ȣ ����
			cus.push_back(customer(temp, j));
		}
		
		//���� �ð����� ����
		//sort(cus.begin(), cus.end());
		findCustomer(cus);
		
		cout << "#" << i << " " << answer << "\n";
	}



	return 0;
}