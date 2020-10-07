/*문자열 세 개 들어오고
s1, s2의 인덱스를 넘겨서 s3의 인덱스 까지의 문자를 구성할 수 있나 ?
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int DATASET;
string s1, s2, s3;
int cache[201][201];
//s1_index = 현재 추가해볼 s1의 위치
//s2_index = 현재 추가해볼 s2의 위치
int interleaving(int s1_index, int s2_index) { //이 위치의 값을 기준으로 s3[s1_index+s2_index] 구성이 가능하면 true
	//base case
	if (s1_index + s2_index == s3.size()) {
		return 1;
	}

	int& ret = cache[s1_index][s2_index];
	if (ret != -1)
		return ret;

	ret = 0;
	if (s1_index < s1.size()) {
		if (s1[s1_index] == s3[s1_index + s2_index]) {
			ret |= interleaving(s1_index + 1, s2_index);
		}
	}
	if (s2_index < s2.size()) {
		if (s2[s2_index] == s3[s1_index + s2_index]) {
			ret |= interleaving(s1_index, s2_index + 1);
		}
	}
	return ret;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);	

	cin >> DATASET;
	for (int i = 0; i < DATASET; i++) {
		fill(&cache[0][0], &cache[200][201], -1);
		cin >> s1 >> s2 >> s3;

		cout << "Data set " << i + 1 << ": ";
		if (interleaving(0, 0))
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}