#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//������ �����ϴ� �ִ�, �ּ� ���ڸ� ã�� ���̴�
//���� ã�� ������ ������ str
//min_str, max_str �� �� ���� �ʿ�

int n;
char inequal[10];
bool visited[10] = { false, };
string str = "";
string min_str = "9999999999";
string max_str = "-1";

//prev�� ���� ���� ��
void dfs(int prev, int current) {
	if (current == n + 1) {
		min_str = min(min_str, str);
		max_str = max(max_str, str);
		return;
	}

	if (inequal[current - 1] == '>') {
		//������ �� ������ ���� �� �־�
		for (int i = 0; i < prev; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				str += (char)(i + '0');
				dfs(i, current + 1);
				visited[i] = false;
				str.erase(current, 1);
			}
		}
	}
	else if (inequal[current - 1] == '<') {
		//������ �� ������ ū �� �־�
		for (int i = prev + 1; i <= 9; i++) {
			if (visited[i] == false) {
				visited[i] = true;
				str += (char)(i + '0');
				dfs(i, current + 1);
				visited[i] = false;
				str.erase(current, 1);
			}
		}
	}
	return;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin >> n;
	//2�� ����
	//�ּ� ���� 021�� �ִ� ���� 897�� ����ϰ� �;�.
	//0���� ����, 9���� ���� �� �� ������
	for (int i = 0; i < n; i++) {
		cin >> inequal[i];
	}

	for (int i = 0; i <= 9; i++) {
		visited[i] = true;
		str += (char)(i + '0');
		dfs(i, 1);
		visited[i] = false;
		str.erase(0, 1);
	}

	cout << max_str << "\n" << min_str;

	return 0;
}