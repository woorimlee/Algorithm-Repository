#include <iostream>
#include <vector>
using namespace std;

int C;
int N;

void PrintPostOrder(vector <int> & pre, vector <int> & in);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> C;
	while (C--) {
		cin >> N;
		int temp;
		vector <int> pre_order;
		vector <int> in_order;
		for (int i = 0; i < N; i++) {
			cin >> temp;
			pre_order.push_back(temp);
		}
		for (int i = 0; i < N; i++) {
			cin >> temp;
			in_order.push_back(temp);
		}
		PrintPostOrder(pre_order, in_order);
	}
	return 0;
}


//�־��� ������ ���� ��ȸ�� �̿��� ���� ��ȸ�� ����� ����.
//Ʈ�� => ��Ʈ ��� + ���� sub tree + ������ sub tree 
//���� ��Ʈ�� ���� ������ ��Ʈ�� �� �� �ڱ� �ڽ� ���.
void PrintPostOrder(vector <int>& pre, vector <int>& in) {
	if (pre.empty()) {
		return;
	}
	int	l_size = 0;
	//pre�� ù ��° ���� in���� ã�Ƽ� �� ���ʿ� �ִ� �͵��� ���� ��Ʈ��, �����ʿ� �ִ� �͵��� ������ ��Ʈ��
	for (int i = 0; i < in.size(); i++) {
		if (in[i] == pre[0]) {
			l_size = i;
			break;
		}
	}
	vector <int> pre_l (pre.begin() + 1, pre.begin() + l_size + 1);
	vector <int> in_l (in.begin(), in.begin() + l_size);
	vector <int> pre_r (pre.begin() + (l_size + 1), pre.begin() + pre.size());
	vector <int> in_r(in.begin() + (l_size + 1), in.begin() + in.size());
	//�� sub
	PrintPostOrder(pre_l, in_l);
	//�� sub
	PrintPostOrder(pre_r, in_r);
	cout << pre[0] << " ";
	return;
}