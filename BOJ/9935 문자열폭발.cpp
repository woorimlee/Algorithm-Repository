#include <string>
#include <iostream>
#include <vector>
using namespace std;

string str; // �Է� ���� ���ڿ�
string bomb; // ���� ���ڿ�
vector <char> ans; // �� ������ ����

int main() {

	cin >> str >> bomb;
	ans.resize(str.size());
	int bs = bomb.size() - 1; //bs == bombsize, bomb�� ������ index.
	
	bool flag = false; //false == ���߹��ڿ� �ƴ�, true == ���� ���ڿ���
	int i = 0, j = 0, k = 0, index = 0;
	for (i = 0; i < str.size(); i++) {
		flag = false;
		//������ ������ �迭�� �Է¹��� ���ڿ��� �ϳ��� ����
		ans[index] = str[i]; 
		
		//���� ����ó�� ������ Ǯ ����.
		//str == ABC4D
		//bomb == C4���, 
		//ans == ABC4�� �Ǵ� ���� 4���� �Ųٷ� ans �迭 �˻�. (4 ������ C���� ã��)
		//�Է¹��� ������ ���� ���� ���� ���ڿ��� �� ������ ���ڶ��,
		if (str[i] == bomb[bs]) { 
			//���� ���ڿ����� �˻���.
			flag = true;
			k = 1;
			for (j = bs - 1; j >= 0; j--) {
				if (ans[index - k] != bomb[j]) {
					flag = false;
					break;
				}
				k++;
			}
		} //�� if���� ������ ���� ���ڿ��� �����Ѵ� ? flag = true : flag = false  

		//���� ���ڿ��� �����ϸ�
		if (flag) {
			//������ ������ �迭�� index ���� ���� ���ڿ��� �����ϴ� ��ġ�� �ű�
			index -= bs;
			continue;
		}
		index++;
	}
	if (index == 0) {
		cout << "FRULA";
		return 0;
	}
	for (int i = 0; i < index; i++) {
		cout << ans[i];
	}

	return 0;
}