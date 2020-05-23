#include <iostream>

using namespace std;

int tree[10001];

void Post(int left, int right);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i = 0;
	while (cin >> tree[i++]);
	//맨 앞의 값을 부모로
	//왼쪽 sub tree는 
	//시작+1 ~ 자기보다 큰 노드 -1
	//오른쪽 sub tree는
	//자기보다 큰 노드 ~ 끝
	
	//왼쪽 섭트리에 대해서 재귀적으로 또 왼, 오 섭트리 구함
	//시작과 끝 값이 같으면 리프노드
	//왼 오 섭트리 재귀 끝나면 cout << 자신(부모)의 노드

	Post(0, i-1);

	return 0;
}

//부모 = 50, 왼쪽 섭트리 30~45, 오른쪽 섭트리 98~60
void Post(int left, int right) {
	if (left > right) {
		return;
	}
	//cout << tree[left] << " " << left << " " << right << "\n";
	//98위치를 찾을 변수
	int branch = left;
	while (branch <= right && tree[left] >= tree[branch]) {
		branch++;
	}

	//left sub tree
	Post(left + 1, branch - 1);
	//right sub tree
	Post(branch, right);
	cout << tree[left] << "\n";

}

/*
#include<iostream>
#include<algorithm>
using namespace std;

int preorder[10005] = {};
void postorder(int s, int e)
{
	if (s  >= e)
		return;
	auto it = upper_bound(preorder + s, preorder + e, preorder[s]);
	//https://blockdmask.tistory.com/168
	//https://modoocode.com/298
	int dist = distance(preorder, it);
	//http://soen.kr/lecture/ccpp/cpp4/39-2-4.htm
	postorder(s + 1, dist);
	postorder(dist, e);
	cout << preorder[s] << "\n";
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int i = 0;
	while (cin >> preorder[i++]);

	postorder(0, i - 1);

}
*/