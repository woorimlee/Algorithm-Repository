#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct {
	int country;
	int id;
	int score;
}info;

//sort ���� ����� �����ֱ� ���� �Լ� ����
bool comp(info a, info b) {
	return a.score > b.score;
}

int cunt[101] = { 0 }; //���� ���� Ƚ��

int main()
{
	int N;
	cin >> N;
	vector <info> res;
	//vector <pair <int, pair <int, int> > > res;
	int country, id, score;
	for (int i = 0; i < N; i++) {
		cin >> country >> id >> score;
		res.push_back({ country, id, score });
	}
	sort(res.begin(), res.end(), comp);

	int medal = 0;
	for(int i = 0; medal != 3; i++) {
		if (cunt[res[i].country] == 2) {
			continue;
		}
		cout << res[i].country << " " << res[i].id << "\n";
		medal++;
		cunt[res[i].country]++;
	}

	return 0;
}