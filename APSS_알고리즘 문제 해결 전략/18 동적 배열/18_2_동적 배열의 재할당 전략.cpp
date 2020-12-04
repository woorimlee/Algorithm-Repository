//���� �迭�� �����ϱ� ���� �ʿ��� ���
//int size : �迭�� ũ��
//ElementType* array : ���� �迭�� ����Ű�� ������
//append(N) : �迭�� �� ���� N�� ����. O(1) ���
//resize(N) : �迭�� ũ�⸦ N���� �ٲ�. O(N)
//N�� append �Լ� ȣ�� �� C(���)�� ����ŭ �迭�� �ø��ٸ�, O(N^2)�� �ð� ���⵵�� �ɸ�. (1�� append() ȣ�� �� O(N))
//N�� append �Լ� ȣ�� �� �������� �þ�� ����ŭ �迭�� �ø��ٸ�(2��� ����), O(N)�� �ð� ���⵵�� �ɸ�. (1�� append() ȣ�� �� O(1))
//N�� append �Լ� ȣ�� �� �迭�� ���� ũ�⸦ �̸� �� �� �ִٸ� N���̵� 1���̵� append()�� O(1)
//C++������ reserve() �Լ��� �迭�� ���� ũ�⸦ �̸� �˾Ƽ� ���Ҵ翡 ��� ����� ���ִ� ������ �����Ѵ�.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//�����͸� ������ ����
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

//����ü NODE�� ����� �迭�� ��ȸ�ϱ� ���� iterator
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
		//reserve�� ����Ǹ� false, �ƴϸ� true�� return

		//������ ���� ���ٸ� �÷�
		bool flag = true;
		if (max_size == cur_size) {
			reserve(max_size * 2);
			flag = false;
		}
		//�� �ڿ� ���� �߰���
		head[cur_size] = NODE<T>(val, nullptr);
		if (cur_size != 0)
			head[cur_size - 1].next = &head[cur_size];
		cur_size++;
		return flag;
	}
		
	int size() { return cur_size; }

	void reserve(int new_capacity) {
	//�迭 ũ�� ���� �Ҵ�, �ű��, ������ ����
		if (new_capacity > max_size) {//������ end - begin ������
			//������ if(new_capacity > max_size()) _Xlength(); -> �ִ��� ����� �� �Ѿ�� �����ص�

			max_size = new_capacity;
			NODE <T>* new_vec = new NODE<T>[max_size];
			umove(new_vec);
			change_array(new_vec);
		}
	}

	void umove(NODE <T>*& new_vec) { //�ű��
		for (int i = 0; i < cur_size; i++) {
			new_vec[i].data = head[i].data;
		}
	}
	
	void change_array(NODE <T>*& new_vec) { //orphan_all ����, �Ӽ� �� �ٲٱ�
		orphan_all(new_vec);
		delete[] head;
		head = new_vec;
	}

	void orphan_all(NODE <T>*& new_vec) { //��� iterator�� nullptr�� ����Ŵ
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
		_Alty_traits ->  allocator_traits ������ max_size : Maximum size possible to allocate. _Getal() : get_allocator
		-> �ִ� numeric_limits ���� allocator �� ��
	_Xlength() : _Xlength_error("vector too long");
	_Reallocate_exactly() : set capacity to _Newcapacity (without geometric growth), provide strong guarantee : guarantee�� exception safety�� ���ϳ�.
		orphan all iterators, discard old array, acquire new array
	
	�ᱹ �׳� n �����ŭ reallocate�� ���̳� (���� ũ�Ⱑ n���� ������)
	*/

	/*myvector<int> myvec;
	myvec.append(1);
	myvec.append(3);
	myvec.append(5);
	myvec.append(7);
	myvec.append(9);
	myvec.append(11);
	�̷������� �ϰ� reserve() ȣ��� �� �� ������ �ȶߴ���, �� ������ 
	https://stackoverflow.com/questions/44093083/c-new-operator-creates-array-of-length-length-1
	���⿡ ����. Undefined behaviour means that the C++ standard imposes no requirements on what happens.
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
