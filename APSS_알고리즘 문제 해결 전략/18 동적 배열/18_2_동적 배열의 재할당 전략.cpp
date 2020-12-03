//동적 배열을 구현하기 위해 필요한 멤버
//int size : 배열의 크기
//ElementType* array : 실제 배열을 가리키는 포인터
//append(N) : 배열의 맨 끝에 N을 삽입. O(1) 희망
//resize(N) : 배열의 크기를 N으로 바꿈. O(N)
//N번 append 함수 호출 시 C(상수)의 값만큼 배열을 늘린다면, O(N^2)의 시간 복잡도가 걸림. (1번 append() 호출 시 O(N))
//N번 append 함수 호출 시 선형으로 늘어나는 값만큼 배열을 늘린다면(2배로 가정), O(N)의 시간 복잡도가 걸림. (1번 append() 호출 시 O(1))
//N번 append 함수 호출 시 배열의 최종 크기를 미리 알 수 있다면 N번이든 1번이든 append()는 O(1)
//C++에서는 reserve() 함수가 배열의 최종 크기를 미리 알아서 재할당에 드는 비용을 없애는 연산을 지원한다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	vector <int> vec;
	int n = 10;
	vec.reserve(n);
	/* reserve(n) : 
	If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
	In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
	
	if (_Newcapacity > capacity()) { // something to do (reserve() never shrinks)
		if (_Newcapacity > max_size()) {
            _Xlength();
         }
        _Reallocate_exactly(_Newcapacity);
    }

	_Newcapacity : n
	capacity() : 
	max_size() : 
	_Xlength() : 
	_Reallocate_exactly() : 

	*/


	return 0;
}