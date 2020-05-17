#include <iostream>
#include <string>
#include <deque>

using namespace std;

bool r_flag = false;
int T, n;
string p, arr;
deque <int> dq;

//R ���� : 
//����� �� �迭�� �տ������� ����ϳ�, �ڿ������� ����ϳĸ� �������ָ� ��.

//D ���� : 
//pop_front & empty() üũ

bool D(deque <int>& dq) {
	if (dq.size() == 0) {
		printf("error\n");
		return false; //������ false�� ����. ���̻� �Լ� ��� ���ϰ�
	}
	else {
		dq.pop_front();
		return true;
	}
}

bool AC() {
	r_flag = false; //true�� R �� ��, false�� R ���Ѱ� or ¦���� �� ��
	int j = 1;
	string snum = "";
	dq.clear();
	cin >> p; //�Լ�
	cin >> n;
	cin >> arr; //�迭

	//�Է¹��� �迭���� ���� �ɰ� ���� �迭��(��) ����ֱ�
	for (auto it : arr) {
		//���ڸ� ���ڿ��� ���صδٰ�
		//���� �ƴѼ��� && ���ڿ��� � ���� �ִٸ�
		//�迭�� �߰��ϰ� ���ڿ� �ʱ�ȭ
		if ('0' <= it && it <= '9') {
			snum += it;
		}
		else if(snum != "") {
			dq.push_back(stoi(snum));
			snum = "";
		}
	}

	//�Լ� �ϳ��� Ȯ���ϸ鼭 ���� �����ϱ�
	for (auto it : p) {
		if (it == 'R') {
			r_flag = !r_flag;
		}
		else { //�Լ��� D��
			if (dq.size() == 0) {
				cout << "error\n";
				return false; //������ false�� ����. ���̻� �Լ� ��� ���ϰ�
			}
			else if(r_flag) { // �Ųٷ� �迭�� �����Ǿ� ������
				dq.pop_back();
			}
			else {
				dq.pop_front();
			}
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> T;
	while (T--) {
		//AC�� �����ϴµ�, error�� �ƴϸ� [�迭��]���
		//AC�� error�� �߻��� ��� false�� return.
		if (AC()) {
			if (dq.empty()) {
				cout << "[]\n";
			}
			else {
				int size = dq.size();
				cout << "[";
				if (r_flag) {//R�� Ȧ�� �� ����Ǹ� �Ųٷ� ���
					for (int i = 0; i < size - 1; i++) {
						cout << dq.back() << ",";
						dq.pop_back();
					}
					cout << dq[0];
				}
				else {
					for (int i = 0; i < size - 1; i++) {
						cout << dq[i] << ",";
					}
					cout << dq.back();
				}
				cout << "]\n";
			}
		}

	}
}