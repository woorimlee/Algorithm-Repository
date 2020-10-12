/*
per_escape : ��Ž���� Ǯ��
dp_escape : dp�� Ǯ��
*/


#include <iostream>
#include <vector>

using namespace std;

int C;
int N, D, P;

//graph = ����� �׷��� ����
//degree = i��° ����� ���� ����
//path = ���ݱ��� Ž���� town ����
//t = ���������� ã�ƺ� town
double per_escape(const vector <vector <int> >& graph, const vector <int>& degree, vector <int>& path, int t) {
	double ret = 0.0;
	if (path.size() == D + 1) {
		if (path.back() == t) {
			ret = 1.0;
			for (int i = 0; i < path.size() - 1; i++) {
				ret /= degree[path[i]];
			}
		}
		return ret;
	}

	for (int i = 0; i < N; i++) {
		if (graph[path.back()][i]) { //���� ��ġ �������� ����Ǿ� ������
			path.push_back(i);
			ret += per_escape(graph, degree, path, t);
			path.pop_back();
		}
	}
	return ret;
}

double cache[51][101];
//graph = ����� �׷��� ����
//degree = i��° ����� ���� ����
//here = ���� ��ġ
//days = ���� �ϼ�
//Ż�� �� days�� ° here�� ���� Ȯ��
double dp_escape(const vector <vector <int> >& graph, const vector <int>& degree, int here, int days) { 
	if (days == 0) {
		return (here == P) ? 1.0 : 0.0;
	}

	double& ret = cache[here][days];
	if (ret != -1.0)
		return ret;

	ret = 0.0;
	for (int next_town = 0; next_town < N; next_town++) {
		if (graph[here][next_town]) {
			ret += (dp_escape(graph, degree, next_town, days - 1) / degree[next_town]);
		}
	}

	return ret;
}

int main() {
	cin >> C;
	while (C--) {
		cin >> N >> D >> P;
		fill(&cache[0][0], &cache[N - 1][D + 1], -1.0);
		vector <vector <int> > graph(N); //����� �׷��� ����
		vector <int> degree(N); //�׷����� i��° ����� ����
		for (int i = 0; i < N; i++) {
			int linked_info, deg_cnt = 0;
			for (int j = 0; j < N; j++) {
				cin >> linked_info;
				if (linked_info == 1)
					deg_cnt++;
				graph[i].push_back(linked_info);
			}
			degree[i] = deg_cnt;
		}
		int T;
		cin >> T;
		while (T--) {
			//vector <int> path(1, P);
			int town;
			cin >> town;
			cout << fixed;
			cout.precision(8);
			//cout << per_escape(graph, degree, path, town) << " ";
			cout << dp_escape(graph, degree, town, D) << " ";
		}
		cout << "\n";
	}
	return 0;
}
