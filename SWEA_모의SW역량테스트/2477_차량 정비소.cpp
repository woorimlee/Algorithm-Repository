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


void findCustomer(vector <customer> &cus, vector <int> a, vector <int> b) {
	int time = 0, endCount = 0;
	queue <int> reception, repair;
	vector <pair <int, int> > receptionINFO; //�� ��ȣ, ���� �ҿ� �ð�
	receptionINFO.resize(a.size());
	vector <int> repairINFO(b.size(), 0);
	while (1) {
		//1. ���� �ð��� ������ �ð��� �Ȱ����� ���� â�� ť�� �ֱ�
		for (int i = 0; i < K; i++) {
			if (cus[i].tk == time) {
				reception.push(i);
			}
		}

		//2-1. ���� â�� ��ȣ �ο�
		//���� â�� ����ְ�, reception ť�� ��� �ο� ������
		for (int i = 0; i < reception.size(); i++) { //���� â�� ť�� �ִ� �ο� �����ŭ
			for (int j = 0; j < receptionINFO.size(); j++) { // ����ó ������ ��ŭ
				if (receptionINFO[j].second == 0) { // ���� j��° ����ó�� ���������
					receptionINFO[j].first = reception.front(); // j��° ����ó�� �� ��ȣ
					receptionINFO[j].second = a[j]; // j ��° ����ó�� ó�� �ð� ����
					cus[receptionINFO[j].first].ak = j+1; // ���� â�� ť���� ��ٸ��� ��(�ش� ��ȣ)�� ����ó ��ȣ ����
					reception.pop();
				}
			}
		}

		//2-2. ���� â�� ���� ��� üũ
		//repair�� �߰� reception���� ���� 
		for (int i = 0; i < receptionINFO.size(); i++) { //���� â�� �����ŭ
			if (receptionINFO[i].second == 0) { // ���� â�� ����ִ� ���� �н�
				continue;
			}
			receptionINFO[i].second--; // �� Ÿ�Ӹ��� ������ ó�� �ð� ����
			
			//���� ������ ó�� �ð��� 0�� �ƴٸ� ������ �� ó���ߴٴ� ��.
			//����ó�� �ڵ����� ����ִ� ���°� �Ǵ�(0�� ��), ���� ���� â�� ť�� �־���.
			if (receptionINFO[i].second == 0) {
				endCount++;
			}
		}

		//3-1. ���� â�� ��ȣ �ο�
		//���� â�� ����ְ�, repair ť�� ��� �ο� ������

		//3-2. ���� â�� ���� ��� üũ
		//��� ���� ���� ��� ���� �߰� repair���� ���� 

		//4. ��� �ο��� ���񽺸� �� ������ while ��
		if (endCount == K) {
			/*cout << endCount << "�׽�Ʈ ��\n";
			for (int i = 0; i < cus.size(); i++) {
				cout << i << "��° ���� ��â ��ȣ : " << cus[i].ak << " ";
			}*/
			break;
		}
		
		time++;
	}
}

int main(void) {
	cin >> T;
	int temp;

	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> K >> A >> B;
		//�ʱ�ȭ
		vector <int> a; //���� â���� �ð� ����
		vector <int> b; //���� â���� �ð� ����
		vector <customer> cus; //�� ���� ����
		answer = -1;

		for (int j = 0; j < N; j++) {
			cin >> temp;
			a.push_back(temp);
		}
		for (int j = 0; j < M; j++) {
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
		findCustomer(cus, a, b);

		cout << "#" << i << " " << answer << "\n";
	}

	return 0;
}