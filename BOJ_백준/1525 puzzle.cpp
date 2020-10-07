#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

//�ּ� �̵��� ���� ���� ���߱�
//���� ���¿��� 1�� ����� �鿩 �ٲ� �� �ִ� ��� ����� ���� ť�� �����ϰ�,
//���� �� ť�� �ִ� ���� �ϳ��� ������ �ٽ� 1�� ����� �鿩 �ٲ� �� �ִ� ��� ����� ���� ť�� �����ϰ�
//... �� ������ �ݺ��Ͽ� �������� �����ϴµ� ��� ����� ���. (BFS ����)

//������ �迭�� ����ؼ� ������ �ذ��ص� ������, 
//ť�� �����ϸ� BFS�˻縦 �� �� ���Ǽ��� ���ؼ� String & int�� �ٲ㼭 ����Ϸ��� ��.
//���� 0 ~ 8���� ���ڸ� �Է¹��� ���ε�, ����ϱ� ���� 0�� 9�� �ٲ�. ��, 1 ~ 9������ �Է¹޴� ���̰�
//012345678�� �ƴ� 123456789�� ���¸� ����°� ����.
//���� �ϳ��� �Է� ���� ������ ���� ���ڿ� *10 �ؼ� ���� �ø�.
//ex) ���� �Է�ó�� 1 0 3 4 2 5 7 8 6�� �Է� �޴´ٸ�
//    ���������� 103425786���� int ���� ������.

int main()
{
	ios::sync_with_stdio(false);

	int start = 0, temp = 0; //�ʱ� �迭 ����
	int now_num, location, new_num;	//while�� �ȿ��� �� ��
	int direct[4][2] = { { -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 } };
	string now_str;
	queue<int> q;
	unordered_map<int, int> ma;

	for (int i = 0; i < 9; i++) {
		cin >> temp;
		if (temp == 0) {
			temp = 9;
		}
		start = start * 10 + temp;
	}

	//BFS ����
	q.push(start);
	ma[start] = 0;
	while (!q.empty())
	{
		now_num = q.front(); q.pop();
		now_str = to_string(now_num);

		//0��(9�� �ٲ� ��) ��ġ�� index�� ã�Ƽ�
		location = now_str.find('9');
		//2���� �迭�̶�� �����߱� ������ x�� y��ǥ ���� ���ϰ�
		int x = location % 3;
		int y = location / 3;

		//�� ������ �˻��� ����. 
		//���� ���¿��� 0�� ��ġ�� �ٲ㰡�� BFS�� �ϸ� ���� ���� �� �ֱ� ������.
		for (int i = 0; i < 4; i++)
		{
			//0�� �ִ� ��ġ�� �����¿� �̵� ������ �� �˻�.(x�� y�� 3x3 �迭���� ������)
			if (0 <= x + direct[i][0] && x + direct[i][0] < 3 &&
				0 <= y + direct[i][1] && y + direct[i][1] < 3) {
				int new_x = x + direct[i][0];
				int new_y = y + direct[i][1];
				string new_str = now_str;
				swap(new_str[y * 3 + x], new_str[new_y * 3 + new_x]);
				new_num = stoi(new_str);

				//������ �˻��� ���� �ƴ϶��(ó�� �˻��� ���̶��).
				if (ma.count(new_num) == 0)
				{
					ma[new_num] = ma[now_num] + 1;
					q.push(new_num);
				}
			}
		}
	}

	//��~~~�� �˻簡 ���� ��, �ʱ� ���¿��� 123456789���� �����ϴµ� ��� �ּ� ��� ���� ���.
	if (ma.count(123456789) == 0)
		cout << "-1" << "\n";
	else
		cout << ma[123456789] << "\n";

	return 0;
}