#include <iostream>
#include <list>

using namespace std;

int main() {
	int N, temp;
	cin >> N;
	//first���� �����ִ� ��, second���� ǳ�� ��ȣ
	list <pair <int, int> > balloon;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		balloon.push_back({ temp, i + 1 });
	}
	int cnt;
	list <pair <int, int>>::iterator it = balloon.begin();
	while (balloon.size()) {
		//ǳ�� ��ȣ ���
		cout << (*it).second << " ";
		//ǳ���� �ϳ��� ���� ���¸� ������ ǳ�� ���� ~ ���� ǳ�� Ž��
		//�κ��� �� �ʿ䰡 ����. ������ ���� �߻���
		if (balloon.size() == 1)
			return 0;

		//cnt�� ������ ǳ�� ��忡 �����ִ� ���� ����ص�
		cnt = it->first;
		//���� ������ ǳ���� ���� ǳ���� ����Ű�� ��
		it = balloon.erase(it);
		//���� ǳ���� ����Ű�� ���� �����ִ� ���� ����� �� 
		//�̹� �� ���� ���� ǳ���� ����Ű�� ������ ������ �� ����.
		//���� ����� ��� �ݺ����� �� �� �� ����
		if (it == balloon.end() && cnt > 0)
			//�� �κ��� ���� ǳ���� �����״µ� end �κ��̶��
			//�� ó�� ǳ���� ����Ű�� ��
			it = balloon.begin();
		if (cnt > 0) {
			for (int j = 0; j < cnt - 1; j++) {
				it++;
				if (it == balloon.end()) {
					it = balloon.begin();
				}
			}
		}
		//������ ���
		else {
			for (int j = 0; j < (cnt * -1); j++) {
				if (it == balloon.begin()) {
					it = balloon.end();
				}
				it--;
			}
		}
	}
	return 0;
}