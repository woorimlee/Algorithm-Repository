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