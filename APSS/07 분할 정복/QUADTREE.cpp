/*쿼드 트리의 대표적인 사용처는 흑백 그림 압축 표현.
교재에서 이터레이터를 이용해 너무 쌈뽕하게 구현해서 본인 풀이 방식 삭제.
기존 방식 :

dir[4] = {3, 4, 1, 2}
string QTR(string s, int idx) { //s에는 현재 살펴볼 문자열, idx는 현재 살펴볼 위치를 위한 오프셋
	if s[idx] == b or w 
		return "b" or "w"

	string ns = "";
	int nidx = idx;
	for(i = 0 ~ 3) {
		nidx = idx + dir[i]
		if s[nidx] == x :
			ns += QTR(s, nidx)
		else 
			ns += s[nidx]
	}

	return ns
}
*/

#include <iostream>
#include <string>

using namespace std;

int C;

string quad_tree_reverse(string::iterator& it) {
	string ns(1, *it);
	it++;

	if (ns == "b" || ns == "w")
		return ns;

	string up_left = quad_tree_reverse(it); 
	string up_right = quad_tree_reverse(it);
	string down_left = quad_tree_reverse(it);
	string down_right = quad_tree_reverse(it);

	ns += down_left + down_right + up_left + up_right;

	return ns;
}

int main() {
	cin >> C;
	while (C--) {
		string picture;
		cin >> picture;
		string::iterator it = picture.begin();
		cout << quad_tree_reverse(it) << "\n";
	}
	return 0;
}