#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//sort 함수에서 사용할 비교 기준 함수
//기본적으론 오름차순
//내림차순 : greater <int>()
//사용자 정의 순서를 만들어주기 위해 아래와 같은 함수를 만듦.
bool comp(pair<int, string> a, pair<int, string> b) {
	//a.first보다 b.first가 크면 놔두고
	if (a.first < b.first) return true;
	//반대면 위치 바꾸기
	return false;
}

int main(void) {
	ios::sync_with_stdio(false);
	
	int n;
	vector <pair <int, string> > vec;
	cin >> n;
	//벡터 인덱스를 사용해 입력받아주려고 resize
	vec.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	//sort()는 정렬 비교하는 두 값이 같을 때 두 elements의 위치를 보존한다고 장담할 수 없는 반면,
	//stable_sort()는 위와 같은 상황에 두 elements의 위치(순서)를 보존해줌.
	//stable_sort : The order of equal elements is guaranteed to be preserved.
	stable_sort(vec.begin(), vec.end(), comp);

	for (auto it : vec) {
		cout << it.first << " " << it.second << '\n';
	}
	return 0;
}