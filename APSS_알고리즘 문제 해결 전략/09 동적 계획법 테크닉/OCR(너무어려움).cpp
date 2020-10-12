#include <iostream>
#include <vector>
#include <string>

using namespace std;

int m,q;
vector <string> str_q;
vector <double> B;
vector <vector <double> > T;
vector <vector <double> > M;
int cache


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//입력 및 초기화
	cin >> m >> q;
	str_q.clear(); B.clear(); T.clear(); M.clear();
	T.resize(m); M.resize(m);
	string s;
	for (int i = 0; i < m; i++) {
		cin >> s;
		str_q.push_back(s);
	}
	double temp;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		B.push_back(temp);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			T[i].push_back(temp);
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			M[i].push_back(temp);
		}
	}


	return 0;
}
