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

	//현 배열에 있는 숫자부터 연속된 5개의 수라고 기대될 배열을 하나 만들어서
	//새로 만든 배열과 기존 배열을 비교
	for (int i = 0; i < vec.size(); i++)
	{
		int cnt = 0;
		//내가 기대하는 올바른 배열
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