#include <iostream>
//BFS용
#include <queue>
//sort()용 
#include <algorithm>
//Undirected Graph용
#include <vector>
using namespace std;

int N, M, V;
bool visited[1001] = { false, };
//undirected graph로 만들기 위한 2차원 벡터 vec.
vector < vector <int> > vec;

int dfs(int now_num) {
	
	visited[now_num] = true;
	cout << now_num << " ";
	for (int i = 0; i < vec[now_num].size(); i++) {
		if (!visited[vec[now_num][i]]) {
			dfs(vec[now_num][i]);
		}
	}
	return 0;
}

//dfs한 후 visited 한 숫자가 true로 바뀐 상황. (true로 초기화 되어있다는 뜻)
int bfs() {
	queue <int> que;

	que.push(V);
	visited[V] = false;
	cout << V << " ";
	while (!que.empty()) {
		int now_num = que.front(); que.pop();
		for (int i = 0; i < vec[now_num].size(); i++) {
			//이미 체크한 숫자가 아니면
			if (visited[vec[now_num][i]]) {
				que.push(vec[now_num][i]);
				visited[vec[now_num][i]] = false;
				cout << vec[now_num][i] << " ";
			}
		}
	}
	return 0;
}

int main(void) {
	cin >> N >> M >> V;
	vec.resize(N+1);

	//undirected Graph 입력 받기. 
	//양방향 연결이니(방향성이 없으니) 1 3을 입력받으면 
	//1 -> 3,   3 -> 1 둘 다 연결 함.
	int temp_a, temp_b;
	while (M--) {
		cin >> temp_a >> temp_b;
		vec[temp_a].push_back(temp_b);
		vec[temp_b].push_back(temp_a);
	}

	//N = 4,   M = 5
	//1 4
	//1 3
	//1 2
	//4 3
	//4 2
	//vec.size = 5
	//sort 후에
	//vec[1] = 2, 3, 4
	//vec[2] = 1, 4
	//vec[3] = 1, 4
	//vec[4] = 1, 2, 3
	
	/* sort 전 상황
	for (int i = 1; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << endl;
	}*/ 

	//작은 숫자부터 순회할 것이니 sort.
	for (int i = 1; i < vec.size(); i++) {
		sort(vec[i].begin(), vec[i].end());
	}

	/* sort 후 상황
	for (int i = 1; i < vec.size(); i++) {
		for (int j = 0; j < vec[i].size(); j++) {
			cout << vec[i][j];
		}
		cout << endl;
	}*/

	dfs(V);
	cout << "\n";
	bfs();

	return 0;
}