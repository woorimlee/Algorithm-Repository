/*���� Ʈ���� ��ǥ���� ���ó�� ��� �׸� ���� ǥ��.
���翡�� ���ͷ����͸� �̿��� �ʹ� �ӻ��ϰ� �����ؼ� ���� Ǯ�� ��� ����.
���� ��� :

dir[4] = {3, 4, 1, 2}
string QTR(string s, int idx) { //s���� ���� ���캼 ���ڿ�, idx�� ���� ���캼 ��ġ�� ���� ������
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