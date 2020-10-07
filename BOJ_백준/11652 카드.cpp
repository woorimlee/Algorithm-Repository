#include <iostream>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int N;
	map <long long, int> card;
	//key == 롱롱형식으로 카드 번호 받아줌.
	//value == 총 이 카드가 몇 번 들어갔는지 저장해줌.

	cin >> N;
	long long card_num;
	for (int i = 0; i < N; i++) {
		cin >> card_num;
		//만약 card_num이 처음 받아본 key 값이라면, 처음 입력된 카드 번호라면
		//card[key] = 1;
		//그게 아니라면
		card[card_num]++;
	}
	//N == 5, 1, 2, 1, 2, 1
	//iterator 반복자 map, vector 요런것들을 순차적으로 순회할 수 있어요.
	//map에 key : value pair가 총 두 개.
	map <long long, int>::iterator it;
	int maximum_num = 0;
	long long answer = 0;
	for (it = card.begin(); it != card.end(); it++) { //nullptr
		//가장 많이 갖고 있는 카드 수는 value 부분에 저장되어 있을것.
		if (maximum_num < (*it).second) {
			maximum_num = (*it).second;
			answer = (*it).first;
		}
	}
	cout << answer;
	return 0;
}