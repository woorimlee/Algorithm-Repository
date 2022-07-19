#include <iostream>
#include <queue>

using namespace std;

int n, w, L;
int truck[1001];

int main() {
	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) 
		cin >> truck[i];
	
	queue <int> q;
	int time = 0, total = 0;
	for (int i = 0; i < n; i++) {
		
		//Ʈ�� ��������
		while (1) {
			//Ʈ���� ���ο� �� �� ��� | �̵����� Ʈ���� �ٸ� �� ���� ��ġ
			if (q.size() == w) {
				total -= q.front();
				q.pop();
			}
			//Ʈ���� �� �־ �Ǹ� Ʈ�� ��������� while ����
			if (total + truck[i] <= L) break;
			//Ʈ�� �� ĭ�� ���� �̵�
			q.push(0);
			time++;
		}
		// ���� Ʈ�� �ֱ�
		q.push(truck[i]);
		total += truck[i];
		time++;
	}
	cout << time + w;
	return 0;
}