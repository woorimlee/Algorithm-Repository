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


//주어진 전위와 중위 순회를 이용해 후위 순회를 출력할 것임.
//트리 => 루트 노드 + 왼쪽 sub tree + 오른쪽 sub tree 
//왼쪽 섭트리 들어가고 오른쪽 섭트리 들어간 뒤 자기 자신 출력.
void PrintPostOrder(vector <int>& pre, vector <int>& in) {
	if (pre.empty()) {
		return;
	}
	int	l_size = 0;
	//pre의 첫 번째 값을 in에서 찾아서 그 왼쪽에 있는 것들은 왼쪽 섭트리, 오른쪽에 있는 것들은 오른쪽 섭트리
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
	//왼 sub
	PrintPostOrder(pre_l, in_l);
	//오 sub
	PrintPostOrder(pre_r, in_r);
	cout << pre[0] << " ";
	return;
}