#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <tuple>
#include <set>

//자료구조 정리
//struct, vector, stack, queue, priority_queue, map, unordered_map, pair, tuple, string, set
//sort & comp 정리

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

void refStack() {
	/* 3. 스택 사용
	자료구조 형식 stack < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수

	*/
}

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

void refMap() {
	/* 6. 우선순위 큐 : 내림차순(기본) 기준으로 값들을 자동 정렬함.
	자료구조 형식 priority_queue < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수
	empty() : 비어있으면 true, 아니면 false return. O(1)
	size() : 크기 반환. O(1)
	top() : 맨 앞에 있는(우선순위 가장 높은) 값 반환. O(1)
	push() : 우선순위 큐에 값 삽입. At most O(N)
	pop() : top에 있는 값 삭제. At most O(N)
	*/
}

void refUnordered_Map() {
	/* 7. 우선순위 큐 : 내림차순(기본) 기준으로 값들을 자동 정렬함.
	자료구조 형식 priority_queue < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수
	empty() : 비어있으면 true, 아니면 false return. O(1)
	size() : 크기 반환. O(1)
	top() : 맨 앞에 있는(우선순위 가장 높은) 값 반환. O(1)
	push() : 우선순위 큐에 값 삽입. At most O(N)
	pop() : top에 있는 값 삭제. At most O(N)
	*/

}

void refTuple() {
	/* 9. 우선순위 큐 : 내림차순(기본) 기준으로 값들을 자동 정렬함.
	자료구조 형식 priority_queue < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수
	empty() : 비어있으면 true, 아니면 false return. O(1)
	size() : 크기 반환. O(1)
	top() : 맨 앞에 있는(우선순위 가장 높은) 값 반환. O(1)
	push() : 우선순위 큐에 값 삽입. At most O(N)
	pop() : top에 있는 값 삭제. At most O(N)
	*/

}

void refSet() {
	/* 11. 우선순위 큐 : 내림차순(기본) 기준으로 값들을 자동 정렬함.
	자료구조 형식 priority_queue < T > 변수 이름;
	T에는 int, char 같은 datatype 혹은 pair 같은 자료구조가 들어갈 수 있다.

	자주 쓰는 함수
	empty() : 비어있으면 true, 아니면 false return. O(1)
	size() : 크기 반환. O(1)
	top() : 맨 앞에 있는(우선순위 가장 높은) 값 반환. O(1)
	push() : 우선순위 큐에 값 삽입. At most O(N)
	pop() : top에 있는 값 삭제. At most O(N)
	*/


}