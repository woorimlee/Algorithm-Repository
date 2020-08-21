#include <iostream>
#include <vector> 
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <tuple>
#include <set>

/* ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
�ڷᱸ�� ����
struct, vector, stack, queue, deque, priority_queue, map, unordered_map, pair, tuple, string, set
sort & compare �Լ� ����� �� ����

//��� ��� : �Ʒ��� ref�Լ����� �� �ڷᱸ���� �����ߴ�.
�� �Լ��� ������ �о�� �ڵ带 ������ ��, main �Լ����� ������� ������� Ȯ���غ���.
����, ref �Լ��鿡�� �ʿ��� �Լ� ���� �� ��ó�� �����ص����� �Բ� ���캸��.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

using namespace std;

void refStruct();
void refString();
void refVector();
bool comp(vector<int> v1, vector<int> v2);
void refPair();
void refTuple();
void refStack();
void refQueue();
void refDeque();
void refPriority_Queue();
void refMap();
void refUnordered_Map();
void refSet();

int main() {
	//refStruct();
	//refString();
	//refVector();
	//refPair();
	//refTuple();
	//refStack();
	//refQueue();
	//refDeque();
	//refPriority_Queue();
	//refMap();
	//refUnordered_Map();
	//refSet();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
	cout << "1. ����ü �ʱ�ȭ\n";
	cout << ms.x << " " << ms.y << " " << ms.node_name << " " << ms.value << "\n";
	cout << ms2.x << " " << ms2.y << " " << ms2.name << "\n\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refString() {
	/* 2. String ��� 
	�ڷᱸ�� ���� String ���� �̸�;

	���� ���� �Լ�
	begin() : ù char ���ͷ����� ��ȯ. Generally O(1)
	end() : ������ char�� ���� ��ġ ���ͷ����� ��ȯ. Generally O(1)
	rbegin() : �� ������ char ���ͷ����� ��ȯ. (�Ųٷ� Ž���ϴ� reverse_iterator�� ���) Generally O(1)
	rend() : �� ù char ���ͷ������� ���� ��ġ ��ȯ. Generally O(1)
	size() : == length(). ���ڿ� ���� ��ȯ. O(1)
	resize() : ��Ʈ�� ���� ������. O(N)
	clear() : �� ����. empty string���� �ٲ�. Generally O(1)
	empty() : ��������� true, �ƴϸ� false. O(1)
	front() : �� ó�� ��ġ�� char reference ������(�� Ȯ�� �� ���� ����) ��ȯ. O(1)
	back() : �� ������ ��ġ�� char reference ������ ��ȯ. O(1)
	at() : �� ��° ��ġ�� �ִ� char ��ȯ. O(1)
	append() : string�� ���ڿ� ���ؼ� Ȯ���ϱ�. �׳� + �����ڸ� ����. O(N)
	push_back() : ���� �ϳ� �� ���� ���ϱ�. Generally O(1) Up to O(N)
	pop_back() : �� ������ ���� ����. Generally O(1)
	insert() : Ư�� ��ġ�� string ����. Generally O(N)
	erase() : Ư�� ��ġ Ȥ�� ������ char ����. Generally O(N)
	replace() : Ư�� ���� ���� �ٲٱ�. Generally O(N)
	find() : ���ڿ� �ȿ��� ���� Ȥ�� ���ڿ� ã�� �� ��ġ�� ��ȯ. Uo to O((N-pos) * M(ã�¹��ڱ���))
	substr() : Ư�� ��ġ���� �� ���� ���ڸ� ��� ���ڿ� ��ȯ. O(N)
	*/

	string s0 = "Hello String";
	string s1(s0, 6, 3); // s0�� ������°���� �� ��
	string s2(10, '^');
	string s3 = s1 + s2;
	cout << "1. �ʱ�ȭ\n";
	cout << s0 << "\n" << s1 << "\n" << s2 << "\n" << s3 << "\n";
	
	cout << "2. ��ȯ\n";
	for (string::iterator it = s0.begin(); it != s0.end(); it++) {
		cout << *it;
	}cout << "\n";
	for (string::reverse_iterator rit = s0.rbegin(); rit != s0.rend(); rit++) {
		cout << *rit;
	}cout << "\n\n";

	string s4 = "Language C++";
	int len = s4.size();
	cout << "3. ��������\n";
	s4.resize(len - 2);
	cout << s4 << "\n";
	s4.resize(s4.size() + 2, '+'); //����� �÷��� �ű⿡ � ���ڸ� ä��
	cout << s4 << "\n\n";

	cout << "4. clear & empty\n";
	s4.clear();
	if (s4.empty()) {
		cout << "s4�� ����ִ�.\n\n";
	}
	
	cout << "5. front & back\n";
	s0.front() = 'h';
	s0.back() = 'G';
	cout << s0 << "\n\n";

	cout << "6. insert & erase & replace\n";
	s0.insert(6, "C++ "); //������ ° ��ġ�� "C++ " ����
	cout << s0 << "\n";
	s0.erase(6, 2); //C+ ����
	cout << s0 << "\n"; 
	s0.erase(s0.begin() + 6); //Ư�� ��ġ�� �ִ� ����(+) ����
	cout << s0 << "\n";
	s0.replace(5, 2, "_");
	cout << s0 << "\n\n";

	cout << "7. substr, find\n";
	cout << s0.substr(6, 3) << " "; //������° ��ġ���� �� ��
	int pos = s0.find("St");
	cout << s0.substr(pos) << "\n\n"; 
	//��ġ�� �����ְ� ���̸� �������� ������ �� ������ ���ڱ��� substr ��ȯ.
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refVector() {
	/* 3. ���� ���
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
	}cout << "\n";

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
	}cout << "\n";

	//2�������� ����ϴ� ��� 2
	const int len = 5;
	vector <int> vec6[len];
	vec6[0].push_back(10);
	vec6[0].push_back(11);
	vec6[1].push_back(3);
	vec6[1].push_back(8);
	vec6[2].push_back(1);
	vec6[2].push_back(9);
	vec6[4].push_back(1);
	vec6[4].push_back(5);
	vec6[4].push_back(12);
	cout << "12.\n";
	for (int i = 0; i < len; i++) {
		cout << "vec6�� " << i << "��° : ";
		for (int j = 0; j < vec6[i].size(); j++) {
			cout << vec6[i][j] << " ";
		}cout << "\n";
	}
	cout << "\n";
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refPair() {
	/* 4. ��� ���
	�ڷᱸ�� ���� pair < T1, T2 > ���� �̸�;
	T1, T2���� int, char ���� datatype Ȥ�� vector ���� �ڷᱸ���� �� �� �ִ�.
	���� vector ���� �ڷᱸ���� �Բ� ���̸�, 2���� ��ǥ ���� ���Ϳ� �����Ѵ��ϸ� �Ʒ�ó�� ������ �����.
	vector <pair <int, int> > vec;

	���� ���� �Լ�
	make_pair() : pair ���� ���� ��������.
	*/
	
	//������ ������ �̸��� ���̸� �����Ϸ��� �Ѵ�.
	//p1 pair�� T1���δ� string��, T2�δ� int�� ����ߴ�.
	pair <string, int> p1;
	p1 = make_pair("Pobi", 11); //make_pair(T1�� ���� ��, T2�� ���� ��) -> pair return
	
	//p2�� ù ��° Ÿ���� string�� ���� �������� .first��, 
	//�� ��° Ÿ�Կ� ���� �������� .second�� ����Ѵ�.
	pair <string, int> p2;
	p2.first = "Porori";
	p2.second = 15;

	//�ʱ�ȭ
	pair <string, int> p3("Porori", 5);

	cout << p1.first << " " << p1.second << "\n";
	cout << p2.first << " " << p2.second << "\n";
	cout << p3.first << " " << p3.second << "\n";
	
	//pair ��Һ�
	//first�� �ִ� �� ���� ���� �� second�� �ִ� ���� ����. 
	//pair ������ �� ���Ǵ� ������� ��������.
	if (p2 == p3) cout << "p2�� p3�� ������ �̸��� ����\n";
	if (p2 != p3) cout << "p2�� p3�� ���� ����\n";
	if (p2 > p3) cout << "p2�� p3���� ŭ(�ʰ�)\n";
	if (p2 < p3) cout << "p2�� p3���� ����(�̸�)\n";
	if (p2 >= p3) cout << "p2�� p3���� ŭ(�̻�)\n\n";
	if (p2 <= p3) cout << "p2�� p3���� ����(����)\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refTuple() {
	/* 5. Ʃ�� : pair�� Ȯ���� �ڷ��� tuple�� 2 �� �̻��� ���� �� ���� ���� ����.
	�ڷᱸ�� ���� tuple < T1, T2, ... > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.

	���� ���� �Լ�
	get() : ����Լ� �ƴ�. get<i>(����) �������� ����, ������ i��° ��ġ�� �����ڸ� ��ȯ�Ѵ�.
	make_tuple() : ����Լ� �ƴ�. Ʃ�� ����� �Լ�.
	*/
	tuple <string, int, int> Node;
	Node = make_tuple("first", 3, 6);
	auto [a, b, c] = Node; //C++17 ����. ������ ���ε�. ����ü�� �ڷᱸ���� ������ ������ �ڵ� �Ҵ�.
	cout << a << " : " << b << ", " << c << "\n\n";
	//���� ������ ���ε��� �������� ������, �Ʒ��� ���� Ʃ�� ���

	string d = std::get<0>(Node); //0��° ��ġ�� ������ ��ȯ(���� ������ �� ����).
	std::get<1>(Node) = 5;
	int e = get<1>(Node);
	int f = get<2>(Node);
	cout << d << " : " << e << ", " << f << "\n\n";

	queue <tuple <int, int, int> > q; //x, y, value ���� �����ؾ� �ϴ� ���
	q.push(make_tuple(3, 4, 5));
	q.push({ 10, -5, 1 });
	q.push({ 0, 9, 19 });

	int q_size = q.size();
	while (q_size--) {
		auto [x, y, val] = q.front();
		q.pop();
		cout << "x : " << x << ", y : " << y << ", �� : " << val << "\n";
	}cout << "\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refStack() {
	/* 6. ���� ���
	�ڷᱸ�� ���� stack < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.
	LIFO �ڷᱸ��

	���� ���� �Լ�
	O(1)
	push() : ���� �� ����(����) ���� ���� 
	pop() : ���� �� ���� �ִ� ���� ����
	size() : ���� ũ�� return
	top() : �� ���� �ִ� ���� return
	empty() : ��������� true��, �ƴϸ� false�� return
	*/

	stack <int> st;
	st.push(1);
	st.push(9);
	st.push(2);
	cout << "���� �� ���� �ִ� �� : " << st.top() << "\n";
	st.pop();
	cout << "���� �� ���� �ִ� �� : " << st.top() << "\n\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refQueue() {
	/* 7. ť ���
	�ڷᱸ�� ���� queue < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.
	FIFO �ڷᱸ��

	���� ���� �Լ�
	O(1)
	push() : ť �� ���� ���� ����
	pop() : �� �տ� �ִ� ���� ����
	size() : ť ũ�� return
	front() : ť�� �� �տ� �ִ� ���� return
	back() : ť�� �� ���� �ִ� ���� return
	empty() : ��������� true, �ƴϸ� false
	*/

	queue <int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << "q�� �� �հ� �� �� : " << q.front() << " " << q.back() << "\n";
	q.pop();
	q.push(1);
	cout << "q�� �� �հ� �� �� : " << q.front() << " " << q.back() << "\n\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refDeque() {
	/* 8. �� ���
	�ڷᱸ�� ���� queue < T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.
	Double-ended queue�� ���Ӹ�. Deque
	front�� end ���ʿ��� ���� �����ϰ� ������ �� �ִ� �ڷᱸ��.
	�ε��� ��� ���� ����
	
	���� ���� �Լ�
	��κ��� ��� O(1)
	push_back() : ���� �� �ڿ� ���� ����
	pop_back() : ���� �� �ڿ� �ִ� ���� ����
	push_front() : ���� �� �տ� ���� ����
	pop_front() : ���� �� �տ� �ִ� ���� ����
	size() : �� ũ�⸦ return
	resize() : ���� ����� ����. O(N). N�� inserted/deleted �� ���� ����
	empty() : ���� ��������� true, �ƴϸ� false�� return
	front() : �� ó�� ���� return
	back() : �� ������ ���� return
	clear() : �� ���� ���� ����. O(N) N�� inserted �� ���� ����
	insert() : Ư�� ��ġ�� �� ����. O(N)
	begin() : �� ���� ��ġ(�ݺ��� ����) ����
	end() : �� ������ ��ġ�� ���� ��ġ(�ݺ��� ����) ����
	*/

	deque <int> deq1;
	deque <int> deq2(5, 0); //5���� ������ 0�� ä��
	deq1.push_back(1);
	deq1.push_back(5);
	deq1.push_front(7);
	deq1.push_front(3);
	
	cout << "deq1�� ����ִ� �� : ";
	for (deque <int>::iterator it = deq1.begin(); it != deq1.end(); it++ ) cout << *it << " ";
	cout << "\n";

	cout << "deq2�� ����ִ� �� : ";
	for (int i = 0; i < deq2.size(); i++) {
		cout << deq2[i] << " ";
	}
	cout << "\n\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refPriority_Queue() {
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refMap() {
	/* 10. �� : Key�� Value�� 1:1 ��Ī �ڷᱸ��.
	�ڷᱸ�� ���� map < K, T > ���� �̸�; 
	pair �������� ���� key�� first, value�� second�� ���ٰ���
	K�� T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.
	map�ڷᱸ���� Key�� �������� �����Ѵ�.
	���� ����Ʈ���� �����Ǳ� ������ �⺻������ ������ �����ϰ�, ���� �ڷᱸ���� ������.

	���� ���� �Լ�
	begin() : O(1)
	end() : O(1)
	empty() : O(1)
	size() : O(1)
	at() : �Լ��� �ѱ� ���� ���� ���� ���� Ű�� Value �����ڸ� ����.(�Ʒ� ��� ���� Ȯ��) O(logN)
	insert() : Key�� Value pair �������� �ڷᱸ���� ����. At most O(logN)
	erase() : Key�� �ѱ��, �ݺ��ڸ� �ѱ��, �ݺ��� ������ �Ѱܼ� �ش��ϴ� Key ����. O(1) ~ O(N)
	clear() : map�� �ִ� ��� elements �� �����ϰ� ����� 0���� �ٲ�. O(N)
	find() : Key�� ã�� ���� ������ �� ��ġ�� iterator ��ȯ. O(logN)
	count() : Key�� �Ѱ� �ش��ϴ� ���� ������ 1��, ������ 0�� return. O(logN)
	�� lower_bound() : lower_bound�� upper_bound()�� algorithm ������� �ִ� �Լ���,
	���� Ž�� ����� Ž�� �Լ���. (Ž���� ���� ������ �Ǿ��־�� ���� Ž���� ����)
	��ȯ ������ �ڷᱸ������ �Լ��� �Ѱ��� ���� ã����, �� ���� ������ �� ������ ū ���� ���� ���� ��ġ�� ã�´�. O(logN)
	�� upper_bound() : �Լ��� �Ѱ��� ���� �ʰ��ϴ� ù ��° ������ ��ġ�� ã�´�. O(logN)
	*/

	//map ���� �� �ʱ�ȭ
	map <string, vector<string> > m = {
		{"Red", {"Apple", "Strawberry"}},
		{"Green", {"Kiwi"}},
		{"Yellow", {}},
		{"Purple", {}}
	};
	vector <string> fruit = m["Red"]; //map m�� Ű "Red"�� �ִ� Value�� ������.
	//Value ���°� vector<string>�̶� ��ȯ ���� ������ fruit ������ �ڷ����� ���� ���� ����.
	for (int i = 0; i < fruit.size(); i++) {
		cout << fruit[i] << ", ";
	}cout << "\n\n";

	//Ư�� key�� �ִ� �� ����
	m["Yellow"] = { "Mango", "Pineapple" };
	m["Green"].push_back("Watermellon"); //value ���°� vector�� push_back �Լ� ��� ����
	for (auto it : m["Yellow"]) { // begin�� end�� �ִ� ��ȯ �ڷᱸ������ �� �պ��� �ϳ��� ���� Ž���ϴ� ���� ���
		cout << it << ", ";
	}cout << "\n\n";
	for (auto it : m["Green"]) {
		cout << it << ", ";
	}cout << "\n\n";

	m.at("Purple") = { "Plum" };
	m.insert({ "Pink", { "Peach" } }); //pair ���·� map �ڷᱸ���� ����. �տ� ���� Key, �ڿ� ���� Value
	auto result = m.find("Purple");
	if (result != m.end()) { 
		cout << result->first << " : " << (*result).second[0] << "\n\n";
	}
	else {
		cout << "Element�� �����ϴ�.\n\n";
	}

	map <char, char> m2;
	m2['a'] = 'A';
	m2['b'] = 'B';
	m2['d'] = 'D';
	m2['h'] = 'H';
	for (char i = 'a'; i <= 'h'; i++) {
		cout << i;
		if (m2.count(i) > 0) 
			cout << " �� m2�� �ֽ��ϴ�. �� : " << m2[i] << "\n";
		else
			cout << " �� m2�� �����ϴ�.""\n";
	}cout << "\n";
	m2['c'] = 'C';
	m2['e'] = 'E';

	map<char, char>::iterator it;
	m2.erase('a'); //key a�� �ش��ϴ� element ����
	it = m2.find('b');
	m2.erase(it); //'b'�� �ݺ��� ��ġ�� �Ѱܼ� ����
	for (auto it : m2) {
		cout << it.first << " " << it.second << "\n";
	}
	m2.erase(m2.begin(), m2.end());
	if (m2.empty()) {
		cout << "m2�� ����ֽ��ϴ�.\n\n";
	}

	map <int, int> m3;
	m3[1] = 50;
	m3[5] = 250;
	m3[10] = 500;
	m3[7] = 350;
	cout << m3.lower_bound(5)->second << "\n";
	cout << m3.upper_bound(5)->second << "\n";
	cout << m3.lower_bound(8)->second << "\n";
	cout << m3.upper_bound(8)->second << "\n";
	cout << m3.lower_bound(10)->second << "\n";
	//cout << m3.upper_bound(10)->second << "\n"; �߸��� ����
	cout << "\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refUnordered_Map() {
	/* 11. ���� �� �� �� : Key�� Value�� 1:1 ��Ī �ڷᱸ��.
	�ڷᱸ�� ���� unordered_map < K, T > ���� �̸�; 
	pair �������� ���� key�� first, value�� second�� ���ٰ���
	K�� T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.
	Key ���� �������� ������ �ʿ䰡 ���� ���, Unordered_map�� ����ؼ� �ӵ��� ����Ű��.
	at, find ���� �Լ��� �翬�� �� ����(���� �� �� �����̴ϱ�)

	���� ���� �Լ�
	begin() : O(1)
	end() : O(1)
	empty() : O(1)
	size() : O(1)
	at() : At most O(N)
	insert() : At most O(N * (size + 1)). N == ���� ���� ��, size == map size.
	erase() : At most O(N)
	clear() : O(N)
	find() : At most O(N)
	count() : At most O(N)
	*/

	unordered_map <char, string> um = {
		{'a', "apple"},
		{'b', "banana"}
	};
	um['c'] = "Cherry";
	for (auto it : um) {
		cout << it.first << " : " << it.second << "\n";
	}cout << "\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refSet() {
	/* 12. �� :	�ߺ��� ������� �ʴ� ������ �����ϴ� �ڷᱸ��.
	�ڷᱸ�� ���� set <	T > ���� �̸�;
	T���� int, char ���� datatype Ȥ�� pair ���� �ڷᱸ���� �� �� �ִ�.
	���� ���� Ʈ���� ������. ���� �ڵ� ����(��������), ��� ��� �ڷᱸ��.

	���� ���� �Լ�. 
	begin() : map�� ����
	end() : map�� ����
	empty() : map�� ����
	size() : map�� ����
	insert() : map�� ����
	erase() : map�� ����
	clear() : map�� ����
	find() : map�� ����
	count() : map�� ����
	lower_bound() : map�� ����
	upper_bound() : map�� ����
	*/

	int arr[] = { 1, 5, 7, 7, 10, 7, 9, 11, 3, 3 };
	set <int> s1(arr, arr + sizeof(arr) / sizeof(int));
	
	//�ڵ� ����, �ߺ��� ���� �������� Ȯ���� �� �ִ�.
	for (auto it : s1) {
		cout << it << ", ";
	}cout << "\n\n";

	set <string> s2;
	s2.insert("apple");
	s2.insert("banana");
	s2.insert("kiwi");
	s2.insert("pig");
	for (auto it : s2) {
		cout << it << ", ";
	}cout << "\n";
	s2.insert("apple");
	s2.insert("banana");
	for (auto it : s2) {
		cout << it << ", ";
	}cout << "\n\n";

	//������ ������ map�� �����ؼ� ����ϰ� ����Ѵ�.
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////