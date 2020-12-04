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

//데이터를 저장할 형식
template <typename T>
struct NODE {
	T data;
	NODE <T>* next;
	NODE() { data = NULL; next = nullptr; }
	NODE(const T& d, NODE<T>* ptr) {
		data = d;
		next = ptr;
	}
};

//구조체 NODE가 저장된 배열을 순회하기 위한 iterator
template <typename T>
class _myiterator {
	NODE <T>* cur;
public :
	_myiterator(NODE <T>* ptr = nullptr) { cur = ptr; }
	_myiterator& operator++() {
		cur = cur->next;
		return *this;
	}
	_myiterator& operator+(int pos) { return *(this + pos); }
	T& operator*() { return cur->data; }
	bool operator==(const _myiterator& it) { return cur == it.cur; }
	bool operator!=(const _myiterator& it) { return cur != it.cur; }
};

template <typename T>
class myvector {
public:
	NODE <T>* head;
	typedef _myiterator<T> iterator;
	int max_size = 4;
	int cur_size = 0;

	myvector() { head = new NODE<T>[max_size]; }

	bool append(T val) {
		//push_back();
		//reserve가 실행되면 false, 아니면 true를 return

		//저장할 곳이 없다면 늘려
		bool flag = true;
		if (max_size == cur_size) {
			reserve(max_size * 2);
			flag = false;
		}
		//맨 뒤에 값을 추가해
		head[cur_size] = NODE<T>(val, nullptr);
		if (cur_size != 0)
			head[cur_size - 1].next = &head[cur_size];
		cur_size++;
		return flag;
	}
		
	int size() { return cur_size; }

	void reserve(int new_capacity) {
	//배열 크기 새로 할당, 옮기기, 기존거 삭제
		if (new_capacity > max_size) {//원래는 end - begin 사이즈
			//원래는 if(new_capacity > max_size()) _Xlength(); -> 최대의 사이즈를 못 넘어가게 설정해둠

			max_size = new_capacity;
			NODE <T>* new_vec = new NODE<T>[max_size];
			umove(new_vec);
			change_array(new_vec);
		}
	}

	void umove(NODE <T>*& new_vec) { //옮기기
		for (int i = 0; i < cur_size; i++) {
			new_vec[i].data = head[i].data;
		}
	}
	
	void change_array(NODE <T>*& new_vec) { //orphan_all 실행, 속성 값 바꾸기
		orphan_all(new_vec);
		delete[] head;
		head = new_vec;
	}

	void orphan_all(NODE <T>*& new_vec) { //모든 iterator가 nullptr을 가리킴
		for (int i = 0; i < cur_size - 1; i++) {
			head[i].next = nullptr;
			new_vec[i].next = &new_vec[i + 1];
		}
	}

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }
};

int main() {
	/*
	vector <int> vec;
	int n = 10;
	vec.reserve(n);
	reserve(n) : 
	If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater).
	In all other cases, the function call does not cause a reallocation and the vector capacity is not affected.
	
	if (_Newcapacity > capacity()) { // something to do (reserve() never shrinks)
		if (_Newcapacity > max_size()) {
            _Xlength();
         }
        _Reallocate_exactly(_Newcapacity);
    }

	_Newcapacity : n
	capacity() : _My_data._Myend - _My_data._Myfirst
	max_size() : min(static_cast<size_type>((numeric_limits<difference_type>::max)()), _Alty_traits::max_size(_Getal())));
		_Alty_traits ->  allocator_traits 여기의 max_size : Maximum size possible to allocate. _Getal() : get_allocator
		-> 최대 numeric_limits 값과 allocator 값 비교
	_Xlength() : _Xlength_error("vector too long");
	_Reallocate_exactly() : set capacity to _Newcapacity (without geometric growth), provide strong guarantee : guarantee는 exception safety를 말하네.
		orphan all iterators, discard old array, acquire new array
	
	결국 그냥 n 사이즈만큼 reallocate가 끝이네 (현재 크기가 n보다 작으면)
	*/

	/*myvector<int> myvec;
	myvec.append(1);
	myvec.append(3);
	myvec.append(5);
	myvec.append(7);
	myvec.append(9);
	myvec.append(11);
	이런식으로 하고 reserve() 호출안 할 때 에러가 안뜨던데, 그 이유가 
	https://stackoverflow.com/questions/44093083/c-new-operator-creates-array-of-length-length-1
	여기에 있음. Undefined behaviour means that the C++ standard imposes no requirements on what happens.
	*/
	myvector<int> myvec;
	myvec.append(1);
	myvec.append(3);
	myvec.append(5);
	myvec.append(7);
	myvec.append(9);
	myvector<int>::iterator it;
	for (it = myvec.begin(); it != myvec.end(); ++it)
		cout << *it << "\n";
	cout << myvec.max_size << " " << myvec.cur_size << "\n";
	return 0;
}
