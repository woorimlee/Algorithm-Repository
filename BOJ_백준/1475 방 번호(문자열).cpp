#include <iostream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

string N;
//0 ~ 9���� ���� ���� Ƚ���� ������ �迭
int room_num[10] = { 0 };
int max_num=INT_MIN;

int main() {
	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		//N�� 9999�� string ���·� �ԷµǾ���,
		//N�� �� �ε����� �����ϸ� '9'��� char�� ��޵Ǵϱ�
		//-'0'�� �ؼ� ���ڷ� �ٲ���.
		room_num[N[i] - '0']++;
	}
	//6�� 9�� �ٲ㾵 �� ������ 9999 -> 6 �� ��, 9 �� ��, 
	// 99999 -> 6 �� ��, 9 �� �� -> �� �� ��Ʈ�� ����ϱ� ���� ��
	int temp_max = (room_num[6] + room_num[9] + 1) / 2;
	for (int i = 0; i <= 9; i++) {
		//�ִ� �ʿ��� ��Ʈ ���� �ľ�
		(i != 6 && i != 9) ? max_num = max(max_num, room_num[i]) : max_num = max(max_num,temp_max);
	}
	cout << max_num;
	return 0;
}