#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N, M, i;
bool visited[32001];
bool finished[32001];
bool flag = false;
vector <vector<int> > vec;
stack <int> ans; //정답 출력용 스택

//너무졸려
void topology_dfs(int cur_node) {
	if (!flag) {
		visited[cur_node] = true;
		for (auto it : vec[cur_node]) {
			if (!visited[it]) {
				topology_dfs(it);
			}
			else if (finished[it] == false) {
				cout << "사이클이 존재합니다.";
				flag = true;
				return;
			}
		}
		//dfs 끝나는 노드들 (맨 끝에서부터) 스택에 추가해둠.
		ans.push(cur_node);
		//검사 끝난 정점은 finished = true;
		finished[cur_node] = true;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	vec.resize(N + 1);
	int A, B;
	for (i = 0; i < M; i++) {
		cin >> A >> B;
		vec[A].push_back(B);
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			topology_dfs(i);
		}
	}
	while (!ans.empty() && !flag) {
		cout << ans.top() << " ";
		ans.pop();
	}
	return 0;
}