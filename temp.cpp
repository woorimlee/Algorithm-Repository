#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <queue>

#define INF 1234567890;

#include <iostream>
using namespace std;
void main() {
	vector <vector <int> > arr(5, vector <int>(5, 1));
	for (auto y : arr) {
		 //y�� �ڷ����� vector <int>
		for (auto x : y) {
			//x�� �ڷ����� int
			cout << x << ", ";
		}
		cout << '\n';
	}
}