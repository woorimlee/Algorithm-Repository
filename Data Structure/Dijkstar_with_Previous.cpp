#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>

#define INF 1234567890;

using namespace std;

struct cityGraph {
	string cityName;
	int howLong;
	cityGraph() { cityName = ""; howLong = 0; }
	cityGraph(string name, int time) : cityName{ name }, howLong{ time } {}
};

unordered_map <string, bool> visited;
void traversalFromSeoul(string city, unordered_map <string, vector<cityGraph> > city_info) {
	// 1) city�� �湮�ߴ�. 2) �̰��������� �� �� �ִ� ��� ���ø� Ž���Ѵ�

	// 1)
	if (!visited[city])
		cout << city << ", ";
	else
		return;
	visited[city] = true;

	// 2)
	for (auto nextCity : city_info[city]) {
		if (!visited[nextCity.cityName])
			traversalFromSeoul(nextCity.cityName, city_info);
	}
}

unordered_map <string, bool> visited2;
void traversalFromSeoulWithin10(string city, int time, unordered_map <string, vector<cityGraph> > city_info) {
	// 1) city�� time �ð����� �湮�߾�. 
	// ó�� �湮�� �����̰� 10�ð� �̳��� ������ ���̸� ȭ�鿡 �����.
	// 2) �̰��������� �� �� �ִ� ��� ���ø� Ž����

	// 1)
	if (!visited2[city] && time < 10) { // ���� ����
		if (city != "����")
			cout << city << ", ";
	}
	else
		return;
	visited2[city] = true;

	// 2)
	for (auto nextCity : city_info[city]) {
		if (!visited2[nextCity.cityName])
			traversalFromSeoulWithin10(nextCity.cityName, time + nextCity.howLong, city_info);
	}
}

int cityToCity(unordered_map <string, vector<cityGraph> > city_info, string start = "����", string dest = "�λ�") {
	unordered_map <string, int> dist;
	for (auto city : city_info)
		dist[city.first] = INF;

	dist[start] = 0;
	priority_queue <pair<int, string> >pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto info = pq.top(); pq.pop();
		int weight = -info.first;
		string city = info.second;
		if (weight > dist[city])
			continue;
		for (auto nextCity : city_info[city]) {
			int new_weight = weight + nextCity.howLong;
			if (new_weight < dist[nextCity.cityName]) {
				dist[nextCity.cityName] = new_weight;
				pq.push({ -new_weight, nextCity.cityName });
			}
		}
	}

	return dist[dest];
}

pair<int, unordered_map <string, string> > cityToCityLog(unordered_map <string, vector<cityGraph> > city_info, string start = "����", string dest = "�λ�") {
	unordered_map <string, int> dist;
	unordered_map <string, string> prev;
	for (auto city : city_info)
		dist[city.first] = INF;

	dist[start] = 0;
	priority_queue <pair<int, string> >pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto info = pq.top(); pq.pop();
		int weight = -info.first;
		string city = info.second;
		if (weight > dist[city])
			continue;
		for (auto nextCity : city_info[city]) {
			int new_weight = weight + nextCity.howLong;
			if (new_weight < dist[nextCity.cityName]) {
				dist[nextCity.cityName] = new_weight;
				pq.push({ -new_weight, nextCity.cityName });
				prev[nextCity.cityName] = city;
			}
		}
	}

	return { dist[dest], prev };
}


int main() {
	unordered_map <string, vector<cityGraph> > cg;
	string A, B;
	int T;
	while (cin >> A >> B >> T) {
		cg[A].emplace_back(B, T);
		cg[B].emplace_back(A, T);
	}

	map <string, int> temp;

	//1. 
	//traversalFromSeoul("����", cg); cout << "\n";

	//2.
	/*unordered_map <string, vector<cityGraph> >::iterator it_cg;
	for (it_cg = cg.begin(); it_cg != cg.end(); it_cg++) {
		traversalFromSeoul(it_cg->first, cg);
		cout << "\n";
	}*/

	//3. 
	//traversalFromSeoulWithin10("����", 0, cg); cout << "\n";

	//4. 
	//cout << cityToCity(cg) << "\n";

	//5.
	pair<int, unordered_map <string, string> > ans = cityToCityLog(cg);
	cout << ans.first << "\n";
	string prev = "�λ�";
	while (prev != "") {
		cout << prev << ", ";
		prev = ans.second[prev];
	} cout << "\n";
	return 0;
}