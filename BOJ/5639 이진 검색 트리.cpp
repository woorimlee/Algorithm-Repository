#include <iostream>

using namespace std;

int tree[10001];

void Post(int left, int right);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int i = 0;
	while (cin >> tree[i++]);
	//�� ���� ���� �θ��
	//���� sub tree�� 
	//����+1 ~ �ڱ⺸�� ū ��� -1
	//������ sub tree��
	//�ڱ⺸�� ū ��� ~ ��
	
	//���� ��Ʈ���� ���ؼ� ��������� �� ��, �� ��Ʈ�� ����
	//���۰� �� ���� ������ �������
	//�� �� ��Ʈ�� ��� ������ cout << �ڽ�(�θ�)�� ���

	Post(0, i-1);

	return 0;
}

//�θ� = 50, ���� ��Ʈ�� 30~45, ������ ��Ʈ�� 98~60
void Post(int left, int right) {
	if (left > right) {
		return;
	}
	//cout << tree[left] << " " << left << " " << right << "\n";
	//98��ġ�� ã�� ����
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