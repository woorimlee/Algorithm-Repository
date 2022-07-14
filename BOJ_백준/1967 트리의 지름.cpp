#include <iostream>
#include <vector>

using namespace std;

//트리 지름을 구하기 위해선 두 가지 경우를 생각해봐야한다.
//1. 현재 노드의 자식 노드들 선에서 지름이 완성되는 경우
//2. 내 자식 노드들 선에서 지름이 완성되지 않는 경우 
//1번의 경우엔 dfs로 자식들 간의 가중치 총 합을 계산해서 전역 변수로 기록해두면 문제를 쉽게 해결할 수 있음
//2번을 해결하기 위해 dfs를 하면서 자신의 위치가 반지름의 중심점이라는 가정하에 하나의 길(노드) 만큼만 값을 return

int N;
int maximum_len = -1; //find_maximum_diameter dfs 함수에서 최대 길이가 구해질 때마다 업데이트 해둠
vector <vector<pair <int, int> > > tree; //first : 자식 노드, second : 길이

int find_maximum_diameter(int cur_node) { //현재 노드를 기준으로 1번의 경우를 계산하고 2번의 경우 값을 return
	int radius_len = 0; //자신의 위치가 반지름의 중심점이 될 수 있으니 최대 반지름 길이 return 
	int second_len = 0; //이진 트리가 아니어서 두 번째 긴 길이를 저장하기 위한 용도

	//cur_node에 연결되어있는 자식 노드들 최대 지름 계산
	for (pair<int, int> it : tree[cur_node]) {
		int cur_len = find_maximum_diameter(it.first) + it.second; //자식이 가져온 최대 길이 + 자식과 연결된 가중치 길이
		
		//최대 반지름 길이 계산
		if (cur_len > radius_len) {
			second_len = radius_len;
			radius_len = cur_len;
		}
		//이진 트리가 아니기 때문에 가장 자식 만으로 만들 수 있는 가장 긴 길이 두 개를 기억해둬야함
		else if (cur_len > second_len)
			//계산한 값이 기존의 최대 반지름 길이보단 짧지만 두 번째 후보보단 긴 경우
			second_len = cur_len;
	}

	//1번 경우를 계산
	if (radius_len + second_len > maximum_len)
		maximum_len = radius_len + second_len;

	return radius_len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	tree.resize(N + 1);
	int p, c, l;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> c >> l;
		tree[p].push_back({ c, l });
	}

	//root 노드는 1부터 시작
	find_maximum_diameter(1);
	cout << maximum_len;
	return 0;
}