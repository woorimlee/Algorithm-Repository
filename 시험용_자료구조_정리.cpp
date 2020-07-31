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
자료구조 정리
struct, vector, stack, queue, priority_queue, map, unordered_map, pair, tuple, string, set
sort & compare 함수 만드는 법 정리

//사용 방법 : 아래의 ref함수에서 각 자료구조를 정리했다.
각 함수의 설명을 읽어보고 코드를 이해한 뒤, main 함수에서 실행시켜 결과값을 확인해보자.
또한, ref 함수들에서 필요한 함수 등은 그 근처에 정의해뒀으니 함께 살펴보자.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

using namespace std;

void refStruct();
void refVec();
bool comp(vector<int> v1, vector<int> v2);
void refStack();
void refQueue();
void refPriority_Queue();
void refMap();
void refUnordered_Map();
void refPair();
void refTuple();
void refString();
void refSet();

int main() {
	//refStruct();
	//refVec();
	//refPriority_Queue();
	//refMap();
	//refUnordered_Map();
	//refTuple();
	//refSet();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
struct make_struct {
	int x, y;
	string node_name;
	float value;
	make_struct(int x, int y, float val, string name) : x{ x }, y{ y }, value{ val }, node_name{ name }{}
	//변수 x에 입력받은 x를 넣고, 변수 y에 입력받은 y를 넣고, value에 입력받은 val을 넣고 ...
};
struct make_struct2 {
	int x, y;
	string name;
};
void refStruct() {
	/* 1. 구조체 초기화 방법
	중괄호 초기화라는 것을 사용할 것임.
	지금 알려주는 방법은 가장 무난한 정석 방법이며, 인수를 생략한 중괄호 초기화, 생성자 등의 다른 방법도 존재한다.
	make_struct와 make_struct2를 참고하자
	*/

	make_struct ms{ 5, 10, 3.9, "first" }; 
	make_struct2 ms2{ 3, 4, "second" }; //중괄호 초기화 등이 없는 경우 구조체에 만든 변수 순서대로 값이 들어간다.
	//즉, ms2의 x는 3, y는 4, name은 second
	cout << ms.x << " " << ms.y << " " << ms.node_name << " " << ms.value << "\n";
	cout << ms2.x << " " << ms2.y << " " << ms2.name << "\n";
	
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refVec() {
	/* 2. 벡터 사용
	자료구조 형식 vector < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수
	대부분의 경우 O(1)
	push_back() : 벡터에 값을 넣는 함수
	pop_back() : 벡터 마지막에 있는 값 삭제
	size() : vector 크기를 return
	resize() : 벡터의 사이즈를 변경. O(N)
	front() : 맨 처음 원소 return
	back() : 맨 마지막 원소 return
	clear() : 벡터 내부 내용 삭제. O(N)
	insert() : 특정 위치에 값 삽입. O(N)
	begin() : 벡터 시작 위치(반복자 형식) 리턴
	end() : 벡터 마지막 위치의 다음 위치(반복자 형식) 리턴
	*/
	vector <int> vec0; //vec1은 int를 저장하는 가변 배열. int vec1[ ? ]와 비슷.
	//vec0[0] = 1; 이런식으로 바로 값을 못 넣어준다. vec0은 배열의 크기가 얼만지 모르기 때문에, 처음에 값을 채워넣기 전에는 인덱스를 사용 못함!
	//위와 같이 벡터 만들고 처음에 값을 집어넣을 때 push_back이 아니라 인덱스를 사용하고 싶다면 resize() 함수를 사용해야 함.

	vec0.push_back(1);
	vec0.push_back(2);
	vec0.push_back(4);
	vec0.push_back(5);
	vec0.push_back(10);
	cout << "1. ";
	for (int i = 0; i < vec0.size(); i++) {
		cout << vec0[i] << " ";
	}cout << "\n\n";

	vector<int>::iterator it; //이터레이터는 순회가 가능한 자료구조의 값들은 맨 앞에서부터 하나씩 접근할 수 있는 반복자
	it = vec0.begin();
	vec0.insert(it + 2, 50);
	vec0.insert(it + 3, 3, 30);
	cout << "2. ";
	for (int i = 0; i < vec0.size(); i++) {
		cout << vec0[i] << " ";
	}cout << "\n\n";

	vec0.pop_back();
	cout << "3. ";
	cout << "vector v0 맨 마지막 원소 : " << vec0.back() << "\n\n";

	swap(vec0[0], vec0[1]); //algorithm 헤더 파일에 있는 swap 함수
	cout << "4. ";
	cout << "vector v0 맨 처음 원소 : " << vec0.front() << "\n\n";

	vec0.clear();
	cout << "5. ";
	if (vec0.empty()) {
		cout << "vec0 비어있음\n\n";
	}

	vector <int> vec1 = { 1, 2, 3, 4 }; //벡터 초기화하는 일반적인 방법. 일반 배열에 넣는것과 똑같음.
	cout << "6. ";
	for (int i = 0; i < vec1.size(); i++) {
		cout << vec1[i] << " ";
	}cout << "\n\n";

	vector <int> vec2(10, 1); //벡터를 초기화하는 두 번째 방법. 10개의 공간에 1을 채움
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

	cout << "8. 정렬 전 : ";
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}cout << "\n";
	sort(vec3.begin(), vec3.end()); //algorithm 헤더 파일에 있는 정렬 함수
	cout << "정렬 후 : ";
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}cout << "\n\n";

	//내림 차순 정렬
	sort(vec3.begin(), vec3.end(), greater<int>()); //greater : 내림차순 형식, <int> : 정렬할 원소의 자료형
	cout << "9. 내림차순 정렬 : ";
	for (int i = 0; i < vec3.size(); i++) {
		cout << vec3[i] << " ";
	}cout << "\n\n";

	//2차원 가변 배열 만드는 방법
	vector <vector <int > > vec4; // 벡터 vec4 각각의 원소들이 저장하는 자료구조가 vector<int>.
	//즉, vec4[0]이 저장하는 게 vector <int>형이라서 vec4[0]은 가변 배열을 저장하고, vec4[1]도 vector<int>를, vec4[2]도 vector<int> ... 결국 2차원 배열이 만들어짐
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

	//2차원 배열의 특정 위치를 저장하는 vec5 배열.
	vector <vector <int> > vec5;
	vec5.push_back({ 5, 10 }); //vec5[0] 번째는 x = 5, y = 10 좌표 값을 저장
	vec5.push_back({ 1, 9 });
	vec5.push_back({ 3, 1 });
	vec5.push_back({ 5, 3 });
	//vec5에 있는 x, y좌표를 다음의 기준으로 정렬할 예정.
	//x 좌표기준으로 오름차순 정렬하면서 x 값이 같은 경우 y값을 기준으로 내림차순 정렬.
	//정렬 후 기댓값 : {1, 9}, {3, 1}, {5, 10}, {5, 3}
	sort(vec5.begin(), vec5.end());
	cout << "11.\n";
	for (int i = 0; i < vec5.size(); i++) {
		cout << vec5[i][0] << " " << vec5[i][1] << "\n";
	}cout << "\n";
	//그냥 정렬하면 원하는 결과 값이 안나옴. y 좌표도 오름차순 정렬이 적용됐기 때문.
	//sort 함수에는 정렬하는 기준을 정의해주는 함수를 만들수 있음. 아래의 comp 함수를 참고.
	sort(vec5.begin(), vec5.end(), comp); //sort의 세 번째 인자로 내가 만든 함수를 넘긴다.
	for (int i = 0; i < vec5.size(); i++) {
		cout << vec5[i][0] << " " << vec5[i][1] << "\n";
	}cout << "\n\n";
}
//비교 기준을 내가 직접 만들기 위해선 bool 자료형의 함수를 만든다.
//v1과 v2 두 개의 매개변수에 대해서 v1을 배열의 왼쪽으로, v2를 배열의 오른쪽으로 보낼 조건을 만들어준다.
bool comp(vector<int> v1, vector<int> v2) {
	if (v1[0] == v2[0]) {
		//만약 v1[0]번째 값과 v2[0]번째 값이 같으면
		//v1[1](왼쪽에 있는 것)이 v2[1](오른쪽에 있는 것)보다 큰 상태로 배열을 정렬해달라.
		return v1[1] > v2[1];
	}
	//나머지 경우엔 v1[0](왼쪽에 있는 것)이 v2[0](오른쪽에 있는 것)보다 작은 상태로 배열을 정렬해달라.
	return v1[0] < v2[0];
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refStack() {
	/* 3. 스택 사용
	자료구조 형식 stack < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수

	*/
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refPriority_Queue() {
	/* 5. 우선순위 큐 : 내림차순(기본) 기준으로 값들을 자동 정렬함.
	자료구조 형식 priority_queue < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수
	empty() : 비어있으면 true, 아니면 false return. O(1)
	size() : 크기 반환. O(1)
	top() : 맨 앞에 있는(우선순위 가장 높은) 값 반환. O(1)
	push() : 우선순위 큐에 값 삽입. At most O(N)
	pop() : top에 있는 값 삭제. At most O(N)
	*/

	priority_queue <int> pq1;
	pq1.push(10); pq1.push(20); pq1.push(1);
	while (!pq1.empty()) {
		cout << pq1.top() << " ";
		pq1.pop();
	}cout << "\n\n";

	//오름차순으로 만드는 방법 1
	priority_queue <int, vector<int>, greater<int> > pq2 ;
	//방법 2
	priority_queue <int, vector<int> > pq3;
	pq2.push(10); pq2.push(20); pq2.push(1);
	pq3.push(-10); pq3.push(-20); pq3.push(-1); // 곱하기 -1을 해줌.
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
	/* 6. 맵 : Key와 Value의 1:1 매칭 자료구조.
	자료구조 형식 map < K, T > 변수 이름; 
	pair 형식으로 들어가서 key는 first, value는 second로 접근가능
	K와 T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.
	map자료구조는 Key를 기준으로 정렬한다.
	균형 이진트리로 구현되기 때문에 기본적으로 정렬을 수행하고, 따라서 자료구조가 느리다.

	자주 쓰는 함수
	begin() : 위와 동
	end() : 위와 동
	empty() : 위와 동
	size() : 위와 동
	at() : 함수에 넘긴 값과 같은 값을 가진 키의 Value 참조자를 리턴.(아래 사용 예시 확인) O(logN)
	insert() : Key랑 Value pair 형식으로 자료구조에 삽입. At most O(logN)
	erase() : Key를 넘기든, 반복자를 넘기든, 반복자 범위를 넘겨서 해당하는 Key 삭제. O(1) ~ O(N)
	clear() : map에 있는 모든 elements 다 삭제하고 사이즈를 0으로 바꿈. O(N)
	find() : Key를 찾아 값이 있으면 그 위치의 iterator 반환. O(logN)
	count() : Key를 넘겨 해당하는 값이 있으면 1을, 없으면 0을 return. O(logN)
	★ lower_bound() : lower_bound와 upper_bound()는 algorithm 헤더에도 있는 함수로,
	이진 탐색 기반의 탐색 함수다. (탐색할 곳은 정렬이 되어있어야 이진 탐색이 가능)
	순환 가능한 자료구조에서 함수에 넘겨준 값을 찾으며, 그 값이 없으면 그 값보다 큰 가장 작은 값의 위치를 찾는다. O(logN)
	★ upper_bound() : 함수에 넘겨준 값을 초과하는 첫 번째 원소의 위치를 찾는다. O(logN)
	*/

	//map 선언 및 초기화
	map <string, vector<string> > m = {
		{"Red", {"Apple", "Strawberry"}},
		{"Green", {"Kiwi"}},
		{"Yellow", {}},
		{"Purple", {}}
	};
	vector <string> fruit = m["Red"]; //map m의 키 "Red"에 있는 Value를 가져옴.
	//Value 형태가 vector<string>이라 반환 값을 저장할 fruit 변수의 자료형을 위와 같이 선언.
	for (int i = 0; i < fruit.size(); i++) {
		cout << fruit[i] << ", ";
	}cout << "\n\n";

	//특정 key에 있는 값 수정
	m["Yellow"] = { "Mango", "Pineapple" };
	m["Green"].push_back("Watermellon"); //value 형태가 vector라 push_back 함수 사용 가능
	for (auto it : m["Yellow"]) { // begin과 end가 있는 순환 자료구조에서 맨 앞부터 하나씩 값을 탐색하는 쉬운 방법
		cout << it << ", ";
	}cout << "\n\n";
	for (auto it : m["Green"]) {
		cout << it << ", ";
	}cout << "\n\n";

	m.at("Purple") = { "Plum" };
	m.insert({ "Pink", { "Peach" } }); //pair 형태로 map 자료구조에 삽입. 앞에 것이 Key, 뒤에 것이 Value
	auto result = m.find("Purple");
	if (result != m.end()) { 
		cout << result->first << " : " << (*result).second[0] << "\n\n";
	}
	else {
		cout << "Element가 없습니다.\n\n";
	}

	map <char, char> m2;
	m2['a'] = 'A';
	m2['b'] = 'B';
	m2['d'] = 'D';
	m2['h'] = 'H';
	for (char i = 'a'; i <= 'h'; i++) {
		cout << i;
		if (m2.count(i) > 0) 
			cout << " 는 m2에 있습니다. 값 : " << m2[i] << "\n";
		else
			cout << " 는 m2에 없습니다.""\n";
	}cout << "\n";
	m2['c'] = 'C';
	m2['e'] = 'E';

	map<char, char>::iterator it;
	m2.erase('a'); //key a에 해당하는 element 삭제
	it = m2.find('b');
	m2.erase(it); //'b'의 반복자 위치를 넘겨서 삭제
	for (auto it : m2) {
		cout << it.first << " " << it.second << "\n";
	}
	m2.erase(m2.begin(), m2.end());
	if (m2.empty()) {
		cout << "m2는 비어있습니다.\n\n";
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
	//cout << m3.upper_bound(10)->second << "\n"; 잘못된 접근
	cout << "\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refUnordered_Map() {
	/* 7. 정렬 안 된 맵 : Key와 Value의 1:1 매칭 자료구조.
	자료구조 형식 unordered_map < K, T > 변수 이름; 
	pair 형식으로 들어가서 key는 first, value는 second로 접근가능
	K와 T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.
	Key 값을 기준으로 정렬할 필요가 없는 경우, Unordered_map을 사용해서 속도를 향상시키자.
	at, find 같은 함수는 당연히 더 느림(정렬 안 된 상태이니까)

	자주 쓰는 함수
	begin() : 위와 동
	end() : 위와 동
	empty() : 위와 동
	size() : 위와 동
	at() : At most O(N)
	insert() : At most O(N * (size + 1)). N == 넣을 값의 수, size == map size.
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
void refTuple() {
	/* 9. 튜플 : pair를 확장한 자료형 tuple은 2 개 이상의 값을 한 번에 저장 가능.
	자료구조 형식 tuple < T1, T2, ... > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수
	get() : 멤버함수 아님. get<i>(변수) 형식으로 쓰며, 변수의 i번째 위치의 참조자를 반환한다.
	make_tuple() : 멤버함수 아님. 튜플 만드는 함수.
	*/
	tuple <string, int, int> Node;
	Node = make_tuple("first", 3, 6);
	auto [a, b, c] = Node; //C++17 문법. 구조적 바인딩. 구조체나 자료구조의 값들을 변수에 자동 할당.
	cout << a << " : " << b << ", " << c << "\n\n";
	//위의 구조적 바인딩이 지원되지 않으면, 아래와 같이 튜플 사용
	
	string d = std::get<0>(Node); //0번째 위치의 참조자 반환(값을 수정할 수 있음).
	std::get<1>(Node) = 5;
	int e = get<1>(Node);
	int f = get<2>(Node);
	cout << d << " : " << e << ", " << f << "\n\n";

	queue <tuple <int, int, int> > q; //x, y, value 값을 저장해야 하는 경우
	q.push(make_tuple(3, 4, 5));
	q.push({ 10, -5, 1 });
	q.push({ 0, 9, 19 });

	int q_size = q.size();
	while (q_size--) {
		auto [x, y, val] = q.front();
		q.pop();
		cout << "x : " << x << ", y : " << y << ", 값 : " << val << "\n";
	}cout << "\n";
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void refSet() {
	/* 11. 셋 :	중복을 허용하지 않는 값들을 저장하는 자료구조.
	자료구조 형식 set <	T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.
	균형 이진 트리로 구현됨. 따라서 자동 정렬(오름차순), 노드 기반 자료구조.

	자주 쓰는 함수. 
	begin() : map과 동일
	end() : map과 동일
	empty() : map과 동일
	size() : map과 동일
	insert() : map과 동일
	erase() : map과 동일
	clear() : map과 동일
	find() : map과 동일
	count() : map과 동일
	lower_bound() : map과 동일
	upper_bound() : map과 동일
	*/

	int arr[] = { 1, 5, 7, 7, 10, 7, 9, 11, 3, 3 };
	set <int> s1(arr, arr + sizeof(arr) / sizeof(int));
	
	//자동 정렬, 중복된 값은 없어짐을 확인할 수 있다.
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

	//나머지 사용법은 map을 참고해서 비슷하게 사용한다.
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////