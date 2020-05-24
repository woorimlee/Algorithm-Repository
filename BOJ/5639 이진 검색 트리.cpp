#include <iostream>
#include <algorithm>

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
	//cout << i << "\n";
	//i는 입력된 갯수 + 1
	Post(0, i-1);

	return 0;
}

//부모 = 50, 왼쪽 섭트리 30~45, 오른쪽 섭트리 98~60
void Post(int left, int right) {
	if (left >= right) {
		return;
	}
	
	//이진 탐색 함수
	//lower bound : 데이터 내 특정 k 값보다 같거나 큰 값이 처음 나오는 위치
	//upper bound : K 값보다 처음으로 큰 값이 나오는 위치
	//upper_bound() : range 안에서 vaㅣ보다 큰 값 찾으면서 다 자기보다 작으면 맨 마지막 위치 리턴
	//last 부분
	auto branch = upper_bound(tree+left, tree+right, tree[left]);
	//advance() : 반복자를 off 만큼 이동시킴
	//distance() : 두 반복자 사이의 거리를 구함 begin() ~ end() == 배열 사이즈
	int dist = distance(tree, branch);
	//cout << tree[left] << " " << left << " " << right << "\n";
	
	//구버전
	//98위치를 찾을 변수
	/*int branch = left;
	while (branch <= right && tree[left] >= tree[branch]) {
		branch++;
	}*/

	//left sub tree
	Post(left + 1, dist);
	//right sub tree
	Post(dist, right);
	cout << tree[left] << "\n";
}

//juyunko님 답 참조
//https://blockdmask.tistory.com/168
//https://modoocode.com/298
//http://soen.kr/lecture/ccpp/cpp4/39-2-4.htm