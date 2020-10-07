#include <string>
#include <iostream>
#include <vector>
using namespace std;

string str; // �Է� ���� ���ڿ�
string bomb; // ���� ���ڿ�
vector <char> ans; // �� ������ ����

void solve_1();
void solve_2();

int main() {
	cin >> str >> bomb;
	ans.resize(str.size());

	solve_1();
	//�ð��ʰ����� �Լ��� �Ἥ Ǫ�� ���
	//solve_2();

	return 0;
}

void solve_1() {
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
	}
	else {
		for (int i = 0; i < index; i++) {
			cout << ans[i];
		}
	}
	return;
}

void solve_2() {
	string::size_type temp = 0;
	//bomb ���ڰ� �� ã���� ������
	while(1){
		temp = str.find(bomb);
		if (temp == string::npos) {
			break;
		}
		str.erase(temp, bomb.size());
		if (temp < bomb.size()) {
			temp = 0;
			continue;
		}
		temp -= bomb.size();
		
	}
	if (str.size() == 0) 
		cout << "FRULA";
	else
		cout << str;
	return;
}