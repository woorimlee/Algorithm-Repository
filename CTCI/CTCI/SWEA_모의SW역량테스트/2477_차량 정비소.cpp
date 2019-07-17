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
	customer(int tk, int k) : tk{ tk }, k{ k } {};
};


void findCustomer(vector <customer> &cus, vector <int> a, vector <int> b) {
	int time = 0, endCount = 0;
	queue <int> reception, repair; //�� ��ȣ
	vector <pair <int, int> > receptionINFO; //�� ��ȣ, ���� �ҿ� �ð�
	vector <pair <int, int> > repairINFO; //�� ��ȣ, ���� �ҿ� �ð�
	receptionINFO.resize(a.size());
	repairINFO.resize(b.size());

	while (1) {
		//1. ���� �ð��� ������ �ð��� �Ȱ����� ���� â�� ť�� �ֱ�
		for (int i = 0; i < K; i++) {
			if (cus[i].tk == time) {
				reception.push(i); // ���� â�� ť�� �� ��ȣ ����
			}
		}


		//2-1. ���� â�� ��ȣ �ο�
		//���� â�� ����ְ�, reception ť�� ��� �ο� ������
		for (int i = 0; i < N; i++) {
			if (reception.empty()) break;
			if (receptionINFO[i].second == 0) { // ���� i��° ����ó�� ��������� && ���� ��� ť �� ������� ����
				receptionINFO[i].first = reception.front(); // i��° ����ó�� �� ��ȣ
				receptionINFO[i].second = a[i]; // i ��° ����ó�� ó�� �ð� ����
				cus[receptionINFO[i].first].ak = i + 1; // ���� â�� ť���� ��ٸ��� ��(�ش� ��ȣ)�� ����ó ��ȣ ����
				reception.pop();
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
				//endCount++;
				repair.push(receptionINFO[i].first); //���� â�� ��� ť�� �� ��ȣ ����.
			}
		}

		//3-1. ���� â�� ��ȣ �ο�
		//���� â�� ����ְ�, repair ť�� ��� �ο� ������
		for (int i = 0; i < M; i++) {
			if (repair.empty()) break;
			if (repairINFO[i].second == 0) { // ���� i��° ����ó�� ��������� && ���� ��� ť �� ������� ����
				repairINFO[i].first = repair.front(); // i��° ����ó�� �� ��ȣ
				repairINFO[i].second = b[i]; // i ��° ����ó�� ó�� �ð� ����
				cus[repairINFO[i].first].bk = i + 1; // ���� â�� ť���� ��ٸ��� ��(�ش� ��ȣ)�� ����ó ��ȣ ����
				repair.pop();
			}
		}
		//3-2. ���� â�� ���� ��� üũ
		//��� ���� ���� ��� ���� �߰� repair���� ���� 
		for (int i = 0; i < repairINFO.size(); i++) { //���� â�� �����ŭ
			if (repairINFO[i].second == 0) { // ���� â�� ����ִ� ���� �н�
				continue;
			}
			repairINFO[i].second--; // �� Ÿ�Ӹ��� ����� ó�� �ð� ����

			//���� ����� ó�� �ð��� 0�� �ƴٸ� ������ �� ó���ߴٴ� ��.
			//����Ҵ� �ڵ����� ����ִ� ���°� �Ǵ�(0�� ��), ��� ���� �� ó���� �� ���ڸ� �÷���.
			if (repairINFO[i].second == 0) {
				endCount++;
			}
		}

		//4. ��� �ο��� ���񽺸� �� ������ while ��
		if (endCount == K) {
			cout << "�׽�Ʈ ��\n";
			for (int i = 0; i < cus.size(); i++) {
				cout << "   " << i << "��° ���� ��â ��ȣ : " << cus[i].ak << " ��â ��ȣ : " << cus[i].bk << " ";
			}cout << endl;
			for (int i = 0; i < K; i++) {
				if (cus[i].ak == A && cus[i].bk == B) {
					answer += (i + 1);
				}
			}
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
		answer = 0;

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

		findCustomer(cus, a, b);
		if (answer == 0) {
			answer = -1;
		}
		cout << "#" << i << " " << answer << "\n";
	}

	return 0;
}