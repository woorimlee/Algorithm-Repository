#include <iostream>
#include <vector>

using namespace std;

//Ʈ�� ������ ���ϱ� ���ؼ� �� ���� ��츦 �����غ����Ѵ�.
//1. ���� ����� �ڽ� ���� ������ ������ �ϼ��Ǵ� ���
//2. �� �ڽ� ���� ������ ������ �ϼ����� �ʴ� ��� 
//1���� ��쿣 dfs�� �ڽĵ� ���� ����ġ �� ���� ����ؼ� ���� ������ ����صθ� ������ ���� �ذ��� �� ����
//2���� �ذ��ϱ� ���� dfs�� �ϸ鼭 �ڽ��� ��ġ�� �������� �߽����̶�� �����Ͽ� �ϳ��� ��(���) ��ŭ�� ���� return

int N;
int maximum_len = -1; //find_maximum_diameter dfs �Լ����� �ִ� ���̰� ������ ������ ������Ʈ �ص�
vector <vector<pair <int, int> > > tree; //first : �ڽ� ���, second : ����

int find_maximum_diameter(int cur_node) { //���� ��带 �������� 1���� ��츦 ����ϰ� 2���� ��� ���� return
	int radius_len = 0; //�ڽ��� ��ġ�� �������� �߽����� �� �� ������ �ִ� ������ ���� return 
	int second_len = 0; //���� Ʈ���� �ƴϾ �� ��° �� ���̸� �����ϱ� ���� �뵵

	//cur_node�� ����Ǿ��ִ� �ڽ� ���� �ִ� ���� ���
	for (pair<int, int> it : tree[cur_node]) {
		int cur_len = find_maximum_diameter(it.first) + it.second; //�ڽ��� ������ �ִ� ���� + �ڽİ� ����� ����ġ ����
		
		//�ִ� ������ ���� ���
		if (cur_len > radius_len) {
			second_len = radius_len;
			radius_len = cur_len;
		}
		//���� Ʈ���� �ƴϱ� ������ ���� �ڽ� ������ ���� �� �ִ� ���� �� ���� �� ���� ����ص־���
		else if (cur_len > second_len)
			//����� ���� ������ �ִ� ������ ���̺��� ª���� �� ��° �ĺ����� �� ���
			second_len = cur_len;
	}

	//1�� ��츦 ���
	if (radius_len + second_len > maximum_len)
		maximum_len = radius_len + second_len;

	return radius_len;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	tree.resize(N + 1);
	int p, c, l;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> c >> l;
		tree[p].push_back({ c, l });
	}

	//root ���� 1���� ����
	find_maximum_diameter(1);
	cout << maximum_len;
	return 0;
}