#include <iostream>
#include <string>
#include <vector>

using namespace std;

int C;
int N, W;
int cache[101][1001];
vector <string> things;
vector <pair <int, int> > things_info; //first = ����, second = ���ڵ�
vector <string> ans;

//pq = packed quantity : ����� �� + ������ ������ ��ȣ
//pv = packed volume
//pq���� �������� pv��ŭ�� ���Ը� ���濡 �������� �� ���ڵ��� ���ΰ�
int packing(int pq, int pv) {
	if (pq == N)
		return 0;
	
	int& ret = cache[pq][pv];
	if (ret != -1) 
		return ret;

	//pq�� 0 ~ N-1������ ���� �ְ� ������ ���������� ���ܼ�
	//�����ϴ� ���� �������� �ʴ� ��� �� ���� ���
	
	//1. ������
	ret = packing(pq + 1, pv);
	//2. ����
	if (pv + things_info[pq].first <= W) 
		ret = max(ret, (packing(pq + 1, pv + things_info[pq].first) + things_info[pq].second));
	return ret;
}

void print_packing_list(int pq, int pv) {
	if (pq == N) {
		return;
	}
		
	if (packing(pq, pv) == packing(pq + 1, pv)) {
		print_packing_list(pq + 1, pv);
	}
	else {
		ans.push_back(things[pq]);
		print_packing_list(pq + 1, pv + things_info[pq].first);
	}
}

int main() {
	cin >> C;
	while (C--) {
		cin >> N >> W;
		fill(&cache[0][0], &cache[N-1][W + 1], -1);
		things.clear(); things_info.clear(); ans.clear();
		string tmp1;//�����̸�
		int tmp2, tmp3;//����, ���ڵ�
		for (int i = 0; i < N; i++) {
			cin >> tmp1 >> tmp2 >> tmp3;
			things.push_back(tmp1);
			things_info.push_back({ tmp2, tmp3 });
		}
		cout << packing(0, 0) << " ";
		print_packing_list(0, 0);
		cout << ans.size() << "\n";
		for (string it : ans)
			cout << it << "\n";
	}
	return 0;
}
