#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, ans;
vector <int> use_order;
vector <int> multitap;

void multitap_scheduling() {
	for (int i = N; i < K; i++) {
		/*cout << i << " : ";
		for (auto it : multitap) {
			cout << it << " ";
		}cout << "\n";*/
		//��Ƽ�� �ȿ� ���� �ֶ��
		if (find(multitap.begin(), multitap.end(), use_order[i]) == multitap.end()) {
			int max_uo_index = -1, max_m_index = 0;
			//��Ƽ�� �ȿ� �ִ� �� �� ���� �ʰ� ���¾� ã��
			for (int j = 0; j < N; j++) {
				int k = i + 1;
				for (; k < K && multitap[j] != use_order[k]; k++) {
					//cout << "j, k : " << j << " " << k << "\n";
				}
				if (max(k, max_uo_index) == k) {
					//cout << "-j, k : " << j << " " << k << "\n";
					max_uo_index = k;
					max_m_index = j;
				}
			}
			//max_m_index ��ġ�� ��Ƽ�ǿ� �����ִ� ��� ����
			multitap.erase(multitap.begin() + max_m_index);
			multitap.push_back(use_order[i]);
			ans++;
		}
	}
}

int main() {
	cin >> N >> K;
	use_order.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> use_order[i];
	}
	
	//�ʱ� ��Ƽ�� ä���
	int i = 0, cnt = 0;
	while(cnt < N) {
		//���� �� ������ ������ �� ��
		if (find(multitap.begin(), multitap.end(), use_order[i]) == multitap.end()) {
			multitap.push_back(use_order[i]);
			cnt++;
		}
		i++;
	}

	//��Ƽ�� �����ٸ�
	multitap_scheduling();

	cout << ans;

	return 0;
}