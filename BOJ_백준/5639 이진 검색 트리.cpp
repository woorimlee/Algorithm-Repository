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
	//�� ���� ���� �θ��
	//���� sub tree�� 
	//����+1 ~ �ڱ⺸�� ū ��� -1
	//������ sub tree��
	//�ڱ⺸�� ū ��� ~ ��
	
	//���� ��Ʈ���� ���ؼ� ��������� �� ��, �� ��Ʈ�� ����
	//���۰� �� ���� ������ �������
	//�� �� ��Ʈ�� ��� ������ cout << �ڽ�(�θ�)�� ���
	//cout << i << "\n";
	//i�� �Էµ� ���� + 1
	Post(0, i-1);

	return 0;
}

//�θ� = 50, ���� ��Ʈ�� 30~45, ������ ��Ʈ�� 98~60
void Post(int left, int right) {
	if (left >= right) {
		return;
	}
	
	//���� Ž�� �Լ�
	//lower bound : ������ �� Ư�� k ������ ���ų� ū ���� ó�� ������ ��ġ
	//upper bound : K ������ ó������ ū ���� ������ ��ġ
	//upper_bound() : range �ȿ��� va�Ӻ��� ū �� ã���鼭 �� �ڱ⺸�� ������ �� ������ ��ġ ����
	//last �κ�
	auto branch = upper_bound(tree+left, tree+right, tree[left]);
	//advance() : �ݺ��ڸ� off ��ŭ �̵���Ŵ
	//distance() : �� �ݺ��� ������ �Ÿ��� ���� begin() ~ end() == �迭 ������
	int dist = distance(tree, branch);
	//cout << tree[left] << " " << left << " " << right << "\n";
	
	//������
	//98��ġ�� ã�� ����
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

//juyunko�� �� ����
//https://blockdmask.tistory.com/168
//https://modoocode.com/298
//http://soen.kr/lecture/ccpp/cpp4/39-2-4.htm