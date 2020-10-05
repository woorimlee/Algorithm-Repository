/*
���� ������ �� �Ÿ�
�� �ɰ��� �ɰ��ſ� ���ؼ� ������ ��� Ǯ ���� �����غ���
���� ��� �� ĥ�� �����غ��� �ǰڱ���.

N^2�÷δ� ������ Ǯ�� ����� ������ �ݾ� �ɰ�����.
���� ������ �߰� ��輱�� �������� ������ �� ���� ����� ���� ����.
1) ���� �������� �ִ� ũ���� ���簢���� ���´�.
2) ������ �������� �ִ� ũ���� ���簢���� ���´�.
3) ��輱�� ���Ե� �κп��� �ִ� ũ���� ���簢���� ���´�.

�̸� ���� base case�� ���� �� ���� �̷��� ��Ÿ���� �����غ���.

find_max_fence(left, right) {
	if left == right
		return plank[left]; // ���� return

	//��輱 ���� ���� ���ڿ� ������ ���� left, right �� ������
	//1)�� 2)�� �Ʒ����� �ذ�
	int ret = max( find_max_fence(���� ����), find_max_fence(������ ����) );

	//3) ��輱�� ���Ե� �κп��� ��ü ��Ÿ���� ���캸�� �ִ� ���簢�� ũ�� ���ϱ�
	int mid = (right + left) / 2
	//¦������ �߰�����, Ȧ���� �߰�
	�߰� ���� ���� or ������ �� �ڱ⺸�� ū ���� ã��


	//1) & 2)�� ����� 3)�� ��� �� max Ȯ���ؼ� return

	//1 2 3 -> m �������� ���� Ȯ��
	//1 3 2 -> �� ���
	//2 1 3 -> m �������� ���� Ȯ��
	//2 3 1 -> ����
	//3 1 2 -> m �������� ������ Ȯ��
	//3 2 1 -> m �������� ������ Ȯ��
	//���� ������ �� �� ū �� ã�Ƽ� Ȯ������.
	lp = mid, rp = mid + 1;
	height = min(plank[lp], plank[rp]);
	while( left <= lp && rp <= right) {
		ret = max(ret, height * (rp - lp + 1));
		//lp-- : ������ �����ʺ��� �� ũ�ų�, ������ �� ã�� ���.
		if((lp - 1) >= left && (plank[lp] > plank[rp] || rp == right)) {
			lp--;
			height = min(height, plank[lp]);
		}
		else {
			rp++;
			height = min(height, plank[rp]);
		}
	}
	return ret;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int C;

int find_max_fence(const vector <int>& plank, int left, int right) {
	//cout << left << " " << right << "\n";
	if (left == right)
		return plank[left];

	int mid = (left + right) / 2;
	int ret = max(find_max_fence(plank, left, mid), find_max_fence(plank, mid + 1, right));
	//cout << " left & right & ret : " << left << " " << right << " " << ret << " ";
	int lp = mid;
	int rp = mid + 1;
	int height = min(plank[lp], plank[rp]);
	ret = max(ret, height * (rp - lp + 1));

	//cout << "-> lp, rp, ret : ";
	while (left < lp || rp < right) {
		//cout << lp << " " << rp << " " << ret << " / ";
		if (rp < right && (lp == left || plank[lp - 1] < plank[rp + 1])) {
			rp++;
			height = min(height, plank[rp]);
		}
		else {
			lp--;
			height = min(height, plank[lp]);
		}
		ret = max(ret, height * (rp - lp + 1));
	}
	//cout << " last ret : " << ret << "\n";
	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		vector <int> plank;
		int h;
		for (int i = 0; i < N; i++) {
			cin >> h;
			plank.push_back(h);
		}
		cout << find_max_fence(plank, 0, N - 1) << "\n";
	}
	return 0;
}