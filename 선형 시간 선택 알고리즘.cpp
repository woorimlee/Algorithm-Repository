#include <iostream>
#include <array>
#include <algorithm>
#include <random>

#define ARRSIZE 10

using namespace std;

/*
n개의 원소로 구성된 배열에서 k 번째 작은 원소를 찾고자 한다면
1) 정렬 -> 2) k번째 작은 원소 찾기
nlogn + k
O(nlogn)의 시간이 걸린다.

이 알고리즘을 O(n)으로 바꾸기 위한 두 가지 방법이 있다.
1. 평균 선형 시간 선택 알고리즘
2. 최악의 경우 선형 시간 선택 알고리즘

1의 경우 O(n) ~ O(n^2)의 속도가 나오는 알고리즘이고,
2의 경우 1번 알고리즘의 최악의 경우를 보완하는 방법으로,
평균 수행시간이 O(n)이 되도록 하는 알고리즘이다.
*/

//난수 생성함수
int GetRandomInt(int min, int max) {
	random_device rd;
	//랜덤 디바이스 객체 생성시 하드웨어의 리소스로 랜덤한 숫자를 생성
	mt19937 mt(rd());
	//메르센 트위스터 엔진에 객체 전달

	//시드 설정 끝

	//난수의 타입을 결정.
	//min~ max까지 모든 숫자 다 나올 수 있음. 닫힌 구간임.
	uniform_int_distribution <int> range(min, max);

	//값 추출
	return range(mt);
}

int LinearTimeSelection(array <int, ARRSIZE> & arr, int s, int e, int k);

int FindMedian(int arr[], int n);
int WorstCaseLinearTimeSelection(array <int, ARRSIZE>& arr, int start, int end, int k);

int main() {
	//for (int T = 0; T < 20; T++) {
		array <int, ARRSIZE> arr;
		for (int i = 0; i < ARRSIZE; i++) {
			arr[i] = GetRandomInt(-5, 10);
		}

		cout << "주어진 배열\n";
		for (auto it : arr) {
			cout << it << " ";
		}

		int k = GetRandomInt(1, ARRSIZE);
		cout << "\n" << k << "번째 작은 원소의 값 :\n";
		//cout << "1. 평균 선형시간 : ";
		//cout << LinearTimeSelection(arr, 0, arr.size() - 1, k) << "\n";
		cout << "2. 최악의 경우 선형 시간 : ";
		cout << WorstCaseLinearTimeSelection(arr, 0, arr.size() - 1, k) << "\n";
		cout << "정렬된 배열 : ";
		sort(arr.begin(), arr.end());
		for (auto it : arr) {
			cout << it << " ";
		}
	//	cout << "\n한 회 끝\n";
	//}
	return 0;
}

int LinearTimeSelection(array <int, ARRSIZE> & arr, int start, int end, int k) {
	/*
	퀵 정렬을 기억하는가?
	pivot을 정하고 피봇보다 작은 값은 배열의 왼쪽에, 큰 값은 오른쪽으로
	값을 이동시키는 알고리즘을 이용할 것이다.
	arr[] = {5, 1, 6, 7, 2}
	2를 pivot으로 잡고 퀵 정렬 한 번 해보면
	arr[] = {1, 2, 6, 7, 5}와 같이 바뀌는데, 이때 교체할 값으로 쓰이던 변수 값은
	1로 나올 것이다. (-> 두번째로 작은 값)
	만약 k번째 작은 원소를 찾는 데 k의 값이 2이면 답 찾은 것이고,
	2보다 작으면 왼쪽 부분에, 2보다 크면 오른쪽 배열에 원하는 답이 있을 것이다.
	*/

	//처음과 끝이 같으면 리턴
	if (start == end) {
		return arr[start];
	}

	//partition
	//피봇이 몇 번째 위친지 구하기
	int i = start; //교체할 인덱스
	int j = start; //비교할 인덱스
	while (j <= end) {
		//피봇보다 작은 놈 찾으면 교체, 큰 놈 찾으면 비교할 놈 위치만 바꾸기
		if (arr[end] >= arr[j]) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	//위 반복문에서 마지막에 i++하기 때문에 피봇의 인덱스 값이 1 증가 된 상태.

	//확인용
	/*
	for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";
	cout << start  <<" " << end << " "  << i<< "\n";*/

	
	//찾는 위치 == 피봇 위치면 답 찾음
	if (k == i) {
		return arr[i - 1];
	}
	//만약 크면 왼쪽으로 재귀
	else if (i > k) {
		return LinearTimeSelection(arr, start, i - 2, k);
	}
	//작으면 오른쪽으로 재귀
	else if (i < k) {
		return LinearTimeSelection(arr, i, end, k);
	}
}


//최악의 상황에도 선형 시간 선택 알고리즘에 쓰일 함수
int FindMedian(int arr[], int n)
{
	sort(arr, arr + n);
	return arr[n / 2];
}
//sort를 너무 남발한것같아. std::sort 함수는 worst case 없이 O(nlogn)에 동작한대.
//이미 정렬된 부분인지 확인하는 함수 하나 만들어서 정렬되어있으면 sort()함수 실행하는거 막아주면 연산속도가 조금 향상되긴 하겠네.
int WorstCaseLinearTimeSelection(array <int, ARRSIZE>& arr, int start, int end, int k) {
	/*
	알고리즘
	1. 전체 배열을 5개씩 나눠 총 n/5개의 그룹을 만든다.
	2. 각 그룹을 정렬하고 중간 값을 찾아낸다. 이때, 각 그룹의 중간 값을 m1, m2, ... mn/5로 명명한다.
	3. m1, m2, ... mn/5의 값 중 중간 값을 본 함수의 재귀함수를 통해 구한다. (k = 배열 크기 / 2로 넘김)
	4. 3에서 구한 중간 값을 M이라고 할 때, M을 배열의 맨 뒤로 보내고 퀵 소트 방식을 이용해 
		M보다 작은 값은 배열의 왼쪽으로, 큰 값은 오른쪽으로 분할한다.
	5. k == M의 위치라면 M의 값을, K > M의 위치라면 오른쪽 배열을, K < M의 위치라면 왼쪽 배열을 탐색한다.
	*/

	//처음과 끝이 같으면 리턴
	if (start == end) {
		return arr[start];
	}
	//5개 이하이면 찾아보고 리턴
	else if (end - start <= 4) {
		sort(arr.begin() + start, arr.begin() + end + 1);
		return arr[k - 1];
	}

	//1 & 2. n/5개의 그룹으로 나누고 중간 값을 저장한다.
	int i=0, size = end-start+1;
	int* median;
	median = new int[(size+ 4) / 5]; //size가 6~ 10이면 두 개 만들어야 하고, ...  
	//cout << "median : ";
	for (i = 0; i < size / 5; i++) {
		//(size+4)/5개 만큼 만들어진 배열 중 맨 마지막 인덱스 빼고는
		//모두 5개씩 비교해볼 수 있음.
		//현재 탐색중인 배열의 첫 위치 + i*5번째부터 5개 중 중간 값 찾기
		median[i] = FindMedian(&arr[start] + start + i * 5, 5);
		//cout << median[i] << " ";
	}
	if (size % 5 != 0) {
		median[i] = FindMedian(&arr[start] + start + i * 5, size % 5);
		//cout << median[i] << "\n";
	}

	//3. m1, m2, ..., mn/5 의 중간 값을 재귀적으로 구한다.
	sort(median, median + (size + 4) / 5);
	int med_of_med = median[((size + 4) / 5) / 2];
	//cout << "medofmed : " << med_of_med << "\n" ;

	//4. M을 pivot으로 퀵 정렬을 수행할 예정.
	//1) M의 index를 구한다.
	i = start;
	for (; i < end; i++) {
		if (arr[i] == med_of_med) {
			break;
		}
	}
	//2) M을 맨 뒤로 보낸다
	//확인용
	/*for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";*/
	swap(arr[i], arr[end]);
	//확인용
	/*for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";*/
	//3) partition 수행
	i = start;
	int j = start;
	while (j <= end) {
		//피봇보다 작은 놈 찾으면 교체, 큰 놈 찾으면 비교할 놈 위치만 바꾸기
		if (arr[end] >= arr[j]) {
			swap(arr[i], arr[j]);
			i++;
		}
		j++;
	}
	//위 반복문에서 마지막에 i++하기 때문에 피봇의 인덱스 값이 1 증가 된 상태.

	//확인용
	/*for (auto it : arr) {
		cout << it << " ";
	}cout << "\n";*/

	//5. M의 인덱스와 k를 비교하고 subarray에 대해 재귀 탐색을 실행한다.
	//찾는 위치 == 피봇 위치면 답 찾음
	if (k == i) {
		return arr[i - 1];
	}
	//만약 크면 왼쪽으로 재귀
	else if (i > k) {
		return WorstCaseLinearTimeSelection(arr, start, i - 2, k);
	}
	//작으면 오른쪽으로 재귀
	else if (i < k) {
		return WorstCaseLinearTimeSelection(arr, i, end, k);
	}
}
