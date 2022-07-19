#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, ans = 5;

int main() {
    cin >> N;
    vector<int> vec(N, 0);

    for (int i = 0; i < N; i++) 
        cin >> vec[i];
    
    sort(vec.begin(), vec.end());

	//�� �迭�� �ִ� ���ں��� ���ӵ� 5���� ����� ���� �迭�� �ϳ� ����
	//���� ���� �迭�� ���� �迭�� ��
	for (int i = 0; i < vec.size(); i++)
	{
		int cnt = 0;
		//���� ����ϴ� �ùٸ� �迭
		vector<int> ans_arr(5, 0);
		for (int j = 0; j < 5; j++)
			ans_arr[j] = vec[i] + j;

		int k = i;
		for (int j = 0; j < 5; j++) {
			if (k < vec.size() && ans_arr[j] == vec[k]) {
				cnt++;
				k++;
			}
		}
		ans = min(ans, 5 - cnt);
	}

	cout << ans;
	return 0;
}