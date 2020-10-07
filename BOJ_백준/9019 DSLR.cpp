#include <iostream>
#include <queue> 
#include <memory.h>
#include <string>

using namespace std;

int main(void) {

	int T;
	cin >> T;
	bool check[10001] = { false, };
	int A, B;

	while (T--) {
		//dslr���� ���� operator�� ����� �ᱣ���� ������ ����.
		queue <pair<string, int> > dslr;
		pair <string, int> now;
		int next;
		cin >> A >> B;
		memset(check, false, sizeof(check));
		dslr.push({ "", A });
		check[A] = true;
		
		while (!dslr.empty()) {
			now = dslr.front(); 
			dslr.pop();

			//�����̸� �ݺ� ��
			if (now.second == B) {
				break;
			}

			//D ������ �ݿ�
			next = (now.second * 2) % 10000;
			if (check[next] == false) {
				//pair�� string �κп��� ���� + D�� ���� ���� �ѱ��
				//pair�� int �κп��� next ���� �Ѱ�
				dslr.push({ now.first + 'D', next });
				check[next] = true;
			}

			//S ������ �ݿ�
			//���� �� -1�� 0�̸� 9999�� �����ϴ°� �ƴ�!
			//���� �� == 0�̸� 9999�� ����, �ƴϸ� -1 �� ����
			next = ((now.second) == 0) ? 9999 : now.second - 1;
			if (check[next] == false) {
				dslr.push({ now.first + 'S', next });
				check[next] = true;
			}

			//L ������ �ݿ�
			next = ((now.second % 1000) * 10) + (now.second / 1000);
			if (check[next] == false) {
				dslr.push({ now.first + 'L', next });
				check[next] = true;
			}

			//R ������ �ݿ�
			next = ((now.second % 10) * 1000) + (now.second / 10);
			if (check[next] == false) {
				dslr.push({ now.first + 'R', next });
				check[next] = true;
			}
		}
		cout << now.first << "\n";
	}

	return 0;
}
