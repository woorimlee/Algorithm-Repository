#include <iostream>
#include <vector>

using namespace std;

void p16();
void p32();
void p42();
void p45();
void p49();
void p55();
void p97();
//97번에서 쓸 벡터
vector < vector <int> > v;
vector < vector <int> > r;

int main() {

	//p16();
	//p32();
	//p43();
	//p44();
	//p49();
	//p55();
	p97();
}

//문제를 잘못 이해한 것 같아~ 입력 받는 형식 다시 살펴봐~
void p16() {
	//n == n, coding == 코딩이 점수, jamding = 잼딩이 점수, num = 입력할 수 
	int n, coding=0, jamding=0, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num%2 == 1) 
			coding++;
		else 
			jamding++;
	}
	if (coding > jamding) 
		printf("o\n");
	else if (coding < jamding) 
		printf("x\n");
	else 
		printf("s\n");
}

//문자 형식은 ' ' 사용해. ""은 문자열 표현할 때 씀.
//문자 배열의 특징은 \n이 맨 마지막에 들어가지 --> 무조건 사이즈가 1 초과임.
//char v[i] 한 공간에 ""를 못담음.
void p32() {
	int a;
		char v[5];
		for (int i = 0; i < 5; i++) {
			cin >> a;
			//C언어에서 조건을 두 개 이상 동시에 주려면 && 써야지?
			//너가 아래처럼 한 방법은 파이썬에서 가능합니다.
			//if (90 < a <= 100) v[i] = 'a';
			//if (80 < a <= 90) v[i] = 'b';
			//if (70 < a <= 80) v[i] = 'c';
			//else v[i] = 'f';
			//그리고 if if if else랑 if, else if, else if, else랑 다름. 31번 문제의 경우 후자의 경우가 훨씬 코딩법임. 
			//과제 : 후자가 더 나은 이유를 메일로 보내줘.
			if (90 < a && a <= 100) v[i] = 'a';
			else if (80 < a && a <= 90) v[i] = 'b';
			else if (70 < a && a <= 80) v[i] = 'c';
			else v[i] = 'f'; 

		}
		for (int i = 0; i < 5; i++) 
			cout << v[i];
}

void p42() {
	int w[5][10];
	int v[10] = { 0, }; //과제 : 초기화 한 이유 메일로 보내줘
	for (int i = 0; i < 10; i++) {
		for (int p = 0; p < 5; p++) {
			cin >> w[p][i];
		}
		for (int p = 0; p < 5; p++) {
			v[i] += w[p][i];
		}
		v[i] = v[i] / 5;
	}
	for (int i = 0; i < 10; i++) {
		//endl 많이 느려. 쓰지말고 "\n"써 무조건.
		//endl 머리에서 잊어
		cout << v[i] << endl;
	}


	/*그리고 문제 답 제출할 때 입력되는 한 줄마다 바로 결과값을 출력해도 됨.
	ex) 1000 2000 3000 4000 5000
		2000 3000 4000 5000 6000
		... 쭉 입력되는 상황에서
		1000 2000 3000 4000 5000 입력되면 평균 계산해서 바로 cout 하세요.
		아래처럼 코딩하라는 뜻임
	*/
	/* 모범 답: 
	void average() { //인자가 필요 없습니다.
		int n, ans=0;
		for (int i = 0; i < 5; i++) {
			cin >> n;
			ans += n;
		}
		cout << ans/5;
		return;
	}
	int main()
	{
		for (int i = 0; i < 10; i++) {
			average();
		}
		return 0;
	}
	*/
}

void p45() {//오류
	int a, b, c;
	cin >> a >> b;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	//a가 b보다 큰 상황인데  (너가 if문으로 처리한게 그 의미임)
	//for 구문을 b까지만 돌려도 되지
	//그리고 0으로 나누는건 오류임
	//i는 1부터 시작해야함. a%0 하면 오류임.
	//그리고 a == 24, b == 12라고 하면 b까지는 검사를 해야지.
	int count = 0;
	for (int i = 1; i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			//약수의 갯수를 저장할건데 c = i를 왜해
			//c = i;
			count++;
			//과제 : 컨티뉴 필요없는 이유 메일로 보내기
			//continue;
		}
	}
	cout << count;
}

void p49() {
	int b, n, p = -100, m = 100;
	for (int i = 0; i < 3; i++) {
		cin >> n;
		if (n > p) p = n;
		if (n < m) m = n;
		else b = n;
		//입력 순서가 10, 3, 2라고 가정.
		//for 구문 처음 실행시 p = 10, m = 10
		//두 번째 실행시 m = 3
		//세 번째 실행시 m = 2
		//for 구문 다 끝나고나면 p = 10, m = 2, b =??
		//알 수 없는 값으로 cout << m / p + b 하고 있으니 제대로 안 됨.
		//if를 실행하면 else문은 안 함.
		//그리고 148번째의 else문은 바로 위 147번째의 if문과만 연결되어 있음. 참고

		//과제 : 이 문제는 너가 하려는 의도는 알았는데 알고리즘이 틀렸으니까 다시 풀어서 메일로 보내줘
	}
	cout << m / p + b;
}

void p55() {//오류
	int n, a, b, r, u, f;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		u = a;
		if (b < a) {
			u = b;
		}
		//b는 작은 수네
		//삼항 연산자라는 걸 쓰면 아래처럼 표현할 수 있음.
		u = a < b ? a : b;	// if(a < b) { u = a} else { u = b}와 동일.
		
		//100 이하의 두 수의 공배수면 100 포함
		for (int t = 1; t <= 100; t++) {
			if (t % a == 0 && t % b == 0) {
				f = t;
				cout << t << " ";
				//컨티뉴 필요 없음
				//continue;
			}
		}
		cout << "\n";
		//아래 for문은 왜 있는거임?
		//for (int t = 1; t * f < 100; t++) {
		//	cout << t * f;
		//}
	}

}

void p97() {
	int a, b, c, d, n;
	/*
	for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++) {
			cin >> n;
			vector <vector <int > > v
			벡터는 가변 배열임
			따라서 사이즈가 안 정해져있음
			사이즈가 얼만지 모르는데 인덱스로 어떻게 접근함. v[i]를 못쓴다는 말임.
			v[i].push_back(n);

			해결 방법 1. vector <int> 하나를 만들어서 거기에 값을 쭉 넣고, int y가 속한 for구문이 끝날 때마다 벡터 전체를 이차원 벡터에 push_back
			해결 방법 2. vector의 사이즈를 정해줌
		}
	}*/

	//해결 방법 1.
	/*vector <int> temp;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> n;
			temp.push_back(n);
		}
		v.push_back(temp);
		temp.clear();
	}*/

	//해결 방법 2.
	/*v.resize(10);
	for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++) {
			cin >> n;
			v[i].push_back(n);
		}
	}*/

	//이차원 벡터 확인용
	/*for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++) {
			cout << v[i][y] << " ";
		}
		cout << "\n";
	}*/

	//그리고 이 문제도 마찬가지로 한 줄씩 입력받아서 실행 결과를 (답? 계산 결과?) 바로 바로 출력해줘 
	//근데 이 문제 상자 입력 경우가 여러 개인 경우가 아니라 딱 한 줄씩 입력되는데? 
	//입력 실행 횟수가 없어.
	//만약 x 번 한다고 하면 아래의 소스 코드를 추가해주면 됨(247, 248, 249, 268번째 줄 주석 제거하면 됨)
	//int x;
	//cin >> x;
	//while (x--) {
		vector <int> box;
		for (int i = 0; i < 10; i++) {
			cin >> n;
			box.push_back(n);
		}
		int id = 0;
		vector <int> ans;
		ans.resize(10); //resize 사용하면 비어있는 인덱스 부분 0으로 초기화 됨.
		for (int i = 0; i < 10; i++) {
			//벡터에 값이 채워지고 난 뒤니까 인덱스로 접근할 수 있음.
			if (box[i] != 0) {
				ans[id] = box[i];
				id++;
			}
		}
		for (int i = 0; i < 10; i++) {
			cout << ans[i] << " ";
		}
	//}

}
