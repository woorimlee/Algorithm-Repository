#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <tuple>
#include <set>

//�ڷᱸ�� ����
//struct, vector, stack, queue, priority_queue, map, unordered_map, pair, tuple, string, set
//sort & comp ����

using namespace std;

void refStruct();
void refVec();
bool comp(vector<int> v1, vector<int> v2);
void refStack();
void refQueue();
void refPriority_Queue();
void refMap();
void refUnorderd_Map();
void refPair();
void refTuple();
void refString();
void refSet();

int main() {
	//refStruct();
	//refVec();
	//refPriority_Queue();
}

struct make_struct {
	int x, y;
	string node_name;
	float value;
	make_struct(int x, int y, float val, string name) : x{ x }, y{ y }, value{ val }, node_name{ name }{}
	//���� x�� �Է¹��� x�� �ְ�, ���� y�� �Է¹��� y�� �ְ�, value�� �Է¹��� val�� �ְ� ...
};
struct make_struct2 {
	int x, y;
	string name;
};
void refStruct() {
	/* 1. ����ü �ʱ�ȭ ���
	�߰�ȣ �ʱ�ȭ��� ���� ����� ����.
	���� �˷��ִ� ����� ���� ������ ���� ����̸�, �μ��� ������ �߰�ȣ �ʱ�ȭ, ������ ���� �ٸ� ����� �����Ѵ�.
	make_struct�� make_struct2�� ��������
	*/

	make_struct ms{ 5, 10, 3.9, "first" }; 
	make_struct2 ms2{ 3, 4, "second" }; //�߰�ȣ �ʱ�ȭ ���� ���� ��� ����ü�� ���� ���� ������� ���� ����.
	//��, ms2�� x�� 3, y�� 4, name�� second
	cout << ms.x << " " << ms.y << " " << ms.node_name << " " << ms.value << "\n";
	cout << ms2.x << " " << ms2.y << " " << ms2.name << "\n";
	
}

void refVec() {
	/* 2. ���� ���
	�ڷᱸ�� ���� vector < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�
	��κ��� ��� O(1)
	push_back() : ���Ϳ� ���� �ִ� �Լ�
	pop_back() : ���� �������� �ִ� �� ����
	size() : vector ũ�⸦ return
	resize() : ������ ����� ����. O(N)
	front() : �� ó�� ���� return
	back() : �� ������ ���� return
	clear() : ���� ���� ���� ����. O(N)
	insert() : Ư�� ��ġ�� �� ����. O(N)
	begin() : ���� ���� ��ġ(�ݺ��� ����) ����
	end() : ���� ������ ��ġ�� ���� ��ġ(�ݺ��� ����) ����
	*/
	vector <int> vec0; //vec1�� int�� �����ϴ� ���� �迭. int vec1[ ? ]�� ���.
	//vec0[0] = 1; �̷������� �ٷ� ���� �� �־��ش�. vec0�� �迭�� ũ�Ⱑ ���� �𸣱� ������, ó���� ���� ä���ֱ� ������ �ε����� ��� ����!
	//���� ���� ���� ����� ó���� ���� ������� �� push_back�� �ƴ϶� �ε����� ����ϰ� �ʹٸ� resize() �Լ��� ����ؾ� ��.

	vec0.push_back(1);
	vec0.push_back(2);
	vec0.push_back(4);
	vec0.push_back(5);
	vec0.push_back(10);
	cout << "1. ";
	for (int i = 0; i < vec0.size(); i++) {
		cout << vec0[i] << " ";
	}cout << "\n\n";

	vector<int>::iterator it; //���ͷ����ʹ� ��ȸ�� ������ �ڷᱸ���� ������ �� �տ������� �ϳ��� ������ �� �ִ� �ݺ���
	it = vec0.begin();
	vec0.insert(it + 2, 50);
	vec0.insert(it + 3, 3, 30);
	cout << "2. ";
	for (int i = 0; i < vec0.size(); i++) {
		cout << vec0[i] << " ";
	}cout << "\n\n";

	vec0.pop_back();
	cout << "3. ";
	cout << "vector v0 �� ������ ���� : " << vec0.back() << "\n\n";

	swap(vec0[0], vec0[1]); //algorithm ��� ���Ͽ� �ִ� swap �Լ�
	cout << "4. ";
	cout << "vector v0 �� ó�� ���� : " << vec0.front() << "\n\n";

	vec0.clear();
	cout << "5. ";
	if (vec0.empty()) {
		cout << "vec0 �������\n\n";
	}

	vector <int> vec1 = { 1, 2, 3, 4 }; //���� �ʱ�ȭ�ϴ� �Ϲ����� ���. �Ϲ� �迭�� �ִ°Ͱ� �Ȱ���.
	cout << "6. ";
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << " ";
	}cout << "\n\n";

	vector <int> vec2(10, 1); //���͸� �ʱ�ȭ�ϴ� �� ��° ���. 10���� ������ 1�� ä��
	cout << "7. ";
	for (int i = 0; i < vec2.size(); i++) {
		cout << vec2[i] << " ";
	}cout << "\n\n";
	
	vector <int> vec3;
	vec3.resize(5);
	vec3[0] = 10;
	vec3[1] = 20;
	vec3[2] = 1;
	vec3[3] = 5;
	vec3[4] = 3;

	cout << "8. ���� �� : ";
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}cout << "\n";
	sort(vec3.begin(), vec3.end()); //algorithm ��� ���Ͽ� �ִ� ���� �Լ�
	cout << "���� �� : ";
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}cout << "\n\n";

	//���� ���� ����
	sort(vec3.begin(), vec3.end(), greater<int>()); //greater : �������� ����, <int> : ������ ������ �ڷ���
	cout << "9. �������� ���� : ";
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}cout << "\n\n";

	//2���� ���� �迭 ����� ���
	vector <vector <int > > vec4; // ���� vec4 ������ ���ҵ��� �����ϴ� �ڷᱸ���� vector<int>.
	//��, vec4[0]�� �����ϴ� �� vector <int>���̶� vec4[0]�� ���� �迭�� �����ϰ�, vec4[1]�� vector<int>��, vec4[2]�� vector<int> ... �ᱹ 2���� �迭�� �������
	vec4.push_back({ 0, 1, 2, 3, 4 });
	vec4.push_back({ 5, 6, 7, 8, 9 });
	vec4.push_back({ 10, 11, 12, 13, 14 });

	cout << "10.\n";
	for (int i = 0; i < vec4.size(); i++) {
		for (int j = 0; j < vec4[i].size(); j++) {
			cout << vec4[i][j] << " ";
		}
		cout << "\n";
	}cout << "\n\n";

	//2���� �迭�� Ư�� ��ġ�� �����ϴ� vec5 �迭.
	vector <vector <int> > vec5;
	vec5.push_back({ 5, 10 }); //vec5[0] ��°�� x = 5, y = 10 ��ǥ ���� ����
	vec5.push_back({ 1, 9 });
	vec5.push_back({ 3, 1 });
	vec5.push_back({ 5, 3 });
	//vec5�� �ִ� x, y��ǥ�� ������ �������� ������ ����.
	//x ��ǥ�������� �������� �����ϸ鼭 x ���� ���� ��� y���� �������� �������� ����.
	//���� �� ��� : {1, 9}, {3, 1}, {5, 10}, {5, 3}
	sort(vec5.begin(), vec5.end());
	cout << "11.\n";
	for (int i = 0; i < vec5.size(); i++) {
		cout << vec5[i][0] << " " << vec5[i][1] << "\n";
	}cout << "\n";
	//�׳� �����ϸ� ���ϴ� ��� ���� �ȳ���. y ��ǥ�� �������� ������ ����Ʊ� ����.
	//sort �Լ����� �����ϴ� ������ �������ִ� �Լ��� ����� ����. �Ʒ��� comp �Լ��� ����.
	sort(vec5.begin(), vec5.end(), comp); //sort�� �� ��° ���ڷ� ���� ���� �Լ��� �ѱ��.
	for (int i = 0; i < vec5.size(); i++) {
		cout << vec5[i][0] << " " << vec5[i][1] << "\n";
	}cout << "\n\n";
}
//�� ������ ���� ���� ����� ���ؼ� bool �ڷ����� �Լ��� �����.
//v1�� v2 �� ���� �Ű������� ���ؼ� v1�� �迭�� ��������, v2�� �迭�� ���������� ���� ������ ������ش�.
bool comp(vector<int> v1, vector<int> v2) {
	if (v1[0] == v2[0]) {
		//���� v1[0]��° ���� v2[0]��° ���� ������
		//v1[1](���ʿ� �ִ� ��)�� v2[1](�����ʿ� �ִ� ��)���� ū ���·� �迭�� �����ش޶�.
		return v1[1] > v2[1];
	}
	//������ ��쿣 v1[0](���ʿ� �ִ� ��)�� v2[0](�����ʿ� �ִ� ��)���� ���� ���·� �迭�� �����ش޶�.
	return v1[0] < v2[0];
}

void refStack() {
	/* 3. ���� ���
	�ڷᱸ�� ���� stack < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�

	*/
}

void refPriority_Queue() {
	/* 5. �켱���� ť : ��������(�⺻) �������� ������ �ڵ� ������.
	�ڷᱸ�� ���� priority_queue < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�
	empty() : ��������� true, �ƴϸ� false return. O(1)
	size() : ũ�� ��ȯ. O(1)
	top() : �� �տ� �ִ�(�켱���� ���� ����) �� ��ȯ. O(1)
	push() : �켱���� ť�� �� ����. At most O(N)
	pop() : top�� �ִ� �� ����. At most O(N)
	*/

	priority_queue <int> pq1;
	pq1.push(10); pq1.push(20); pq1.push(1);
	while (!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}cout << "\n\n";

	//������������ ����� ��� 1
	priority_queue <int, vector<int>, greater<int> > pq2 ;
	//��� 2
	priority_queue <int, vector<int> > pq3;
	pq2.push(10); pq2.push(20); pq2.push(1);
	pq3.push(-10); pq3.push(-20); pq3.push(-1); // ���ϱ� -1�� ����.
	while (!pq2.empty()) {
		cout << pq2.top() << " ";
		pq2.pop();
	}cout << "\n";
	while (!pq3.empty()) {
		cout << pq3.top() << " ";
		pq3.pop();
	}cout << "\n\n";

	vector <int> myvec = { 10, 20, 6, 1, -5 };
	priority_queue <int> pq4(myvec.begin(), myvec.end());
	while (!pq4.empty()) {
		cout << pq4.top() << " ";
		pq4.pop();
	}cout << "\n\n";
}

void refMap() {
	/* 6. �켱���� ť : ��������(�⺻) �������� ������ �ڵ� ������.
	�ڷᱸ�� ���� priority_queue < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�
	empty() : ��������� true, �ƴϸ� false return. O(1)
	size() : ũ�� ��ȯ. O(1)
	top() : �� �տ� �ִ�(�켱���� ���� ����) �� ��ȯ. O(1)
	push() : �켱���� ť�� �� ����. At most O(N)
	pop() : top�� �ִ� �� ����. At most O(N)
	*/
}

void refUnordered_Map() {
	/* 7. �켱���� ť : ��������(�⺻) �������� ������ �ڵ� ������.
	�ڷᱸ�� ���� priority_queue < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�
	empty() : ��������� true, �ƴϸ� false return. O(1)
	size() : ũ�� ��ȯ. O(1)
	top() : �� �տ� �ִ�(�켱���� ���� ����) �� ��ȯ. O(1)
	push() : �켱���� ť�� �� ����. At most O(N)
	pop() : top�� �ִ� �� ����. At most O(N)
	*/

}

void refTuple() {
	/* 9. �켱���� ť : ��������(�⺻) �������� ������ �ڵ� ������.
	�ڷᱸ�� ���� priority_queue < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�
	empty() : ��������� true, �ƴϸ� false return. O(1)
	size() : ũ�� ��ȯ. O(1)
	top() : �� �տ� �ִ�(�켱���� ���� ����) �� ��ȯ. O(1)
	push() : �켱���� ť�� �� ����. At most O(N)
	pop() : top�� �ִ� �� ����. At most O(N)
	*/

}

void refSet() {
	/* 11. �켱���� ť : ��������(�⺻) �������� ������ �ڵ� ������.
	�ڷᱸ�� ���� priority_queue < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�
	empty() : ��������� true, �ƴϸ� false return. O(1)
	size() : ũ�� ��ȯ. O(1)
	top() : �� �տ� �ִ�(�켱���� ���� ����) �� ��ȯ. O(1)
	push() : �켱���� ť�� �� ����. At most O(N)
	pop() : top�� �ִ� �� ����. At most O(N)
	*/


}