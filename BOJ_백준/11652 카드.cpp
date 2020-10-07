#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	map <long long, int> card;
	//key == �շ��������� ī�� ��ȣ �޾���.
	//value == �� �� ī�尡 �� �� ������ ��������.

	cin >> N;
	long long card_num;
	for (int i = 0; i < N; i++) {
		cin >> card_num;
		//���� card_num�� ó�� �޾ƺ� key ���̶��, ó�� �Էµ� ī�� ��ȣ���
		//card[key] = 1;
		//�װ� �ƴ϶��
		card[card_num]++;
	}
	//N == 5, 1, 2, 1, 2, 1
	//iterator �ݺ��� map, vector �䷱�͵��� ���������� ��ȸ�� �� �־��.
	//map�� key : value pair�� �� �� ��.
	map <long long, int>::iterator it;
	int maximum_num = 0;
	long long answer = 0;
	for (it = card.begin(); it != card.end(); it++) { //nullptr
		//���� ���� ���� �ִ� ī�� ���� value �κп� ����Ǿ� ������.
		if (maximum_num < (*it).second) {
			maximum_num = (*it).second;
			answer = (*it).first;
		}
	}
	cout << answer;
	return 0;
}