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
//97������ �� ����
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

//������ �߸� ������ �� ����~ �Է� �޴� ���� �ٽ� �����~
void p16() {
	//n == n, coding == �ڵ��� ����, jamding = ����� ����, num = �Է��� �� 
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

//���� ������ ' ' �����. ""�� ���ڿ� ǥ���� �� ��.
//���� �迭�� Ư¡�� \n�� �� �������� ���� --> ������ ����� 1 �ʰ���.
//char v[i] �� ������ ""�� ������.
void p32() {
	int a;
		char v[5];
		for (int i = 0; i < 5; i++) {
			cin >> a;
			//C���� ������ �� �� �̻� ���ÿ� �ַ��� && �����?
			//�ʰ� �Ʒ�ó�� �� ����� ���̽㿡�� �����մϴ�.
			//if (90 < a <= 100) v[i] = 'a';
			//if (80 < a <= 90) v[i] = 'b';
			//if (70 < a <= 80) v[i] = 'c';
			//else v[i] = 'f';
			//�׸��� if if if else�� if, else if, else if, else�� �ٸ�. 31�� ������ ��� ������ ��찡 �ξ� �ڵ�����. 
			//���� : ���ڰ� �� ���� ������ ���Ϸ� ������.
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
	int v[10] = { 0, }; //���� : �ʱ�ȭ �� ���� ���Ϸ� ������
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
		//endl ���� ����. �������� "\n"�� ������.
		//endl �Ӹ����� �ؾ�
		cout << v[i] << endl;
	}


	/*�׸��� ���� �� ������ �� �ԷµǴ� �� �ٸ��� �ٷ� ������� ����ص� ��.
	ex) 1000 2000 3000 4000 5000
		2000 3000 4000 5000 6000
		... �� �ԷµǴ� ��Ȳ����
		1000 2000 3000 4000 5000 �ԷµǸ� ��� ����ؼ� �ٷ� cout �ϼ���.
		�Ʒ�ó�� �ڵ��϶�� ����
	*/
	/* ��� ��: 
	void average() { //���ڰ� �ʿ� �����ϴ�.
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

void p45() {//����
	int a, b, c;
	cin >> a >> b;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	//a�� b���� ū ��Ȳ�ε�  (�ʰ� if������ ó���Ѱ� �� �ǹ���)
	//for ������ b������ ������ ����
	//�׸��� 0���� �����°� ������
	//i�� 1���� �����ؾ���. a%0 �ϸ� ������.
	//�׸��� a == 24, b == 12��� �ϸ� b������ �˻縦 �ؾ���.
	int count = 0;
	for (int i = 1; i <= b; i++) {
		if (a % i == 0 && b % i == 0) {
			//����� ������ �����Ұǵ� c = i�� ����
			//c = i;
			count++;
			//���� : ��Ƽ�� �ʿ���� ���� ���Ϸ� ������
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
		//�Է� ������ 10, 3, 2��� ����.
		//for ���� ó�� ����� p = 10, m = 10
		//�� ��° ����� m = 3
		//�� ��° ����� m = 2
		//for ���� �� �������� p = 10, m = 2, b =??
		//�� �� ���� ������ cout << m / p + b �ϰ� ������ ����� �� ��.
		//if�� �����ϸ� else���� �� ��.
		//�׸��� 148��°�� else���� �ٷ� �� 147��°�� if������ ����Ǿ� ����. ����

		//���� : �� ������ �ʰ� �Ϸ��� �ǵ��� �˾Ҵµ� �˰����� Ʋ�����ϱ� �ٽ� Ǯ� ���Ϸ� ������
	}
	cout << m / p + b;
}

void p55() {//����
	int n, a, b, r, u, f;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		u = a;
		if (b < a) {
			u = b;
		}
		//b�� ���� ����
		//���� �����ڶ�� �� ���� �Ʒ�ó�� ǥ���� �� ����.
		u = a < b ? a : b;	// if(a < b) { u = a} else { u = b}�� ����.
		
		//100 ������ �� ���� ������� 100 ����
		for (int t = 1; t <= 100; t++) {
			if (t % a == 0 && t % b == 0) {
				f = t;
				cout << t << " ";
				//��Ƽ�� �ʿ� ����
				//continue;
			}
		}
		cout << "\n";
		//�Ʒ� for���� �� �ִ°���?
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
			���ʹ� ���� �迭��
			���� ����� �� ����������
			����� ���� �𸣴µ� �ε����� ��� ������. v[i]�� �����ٴ� ����.
			v[i].push_back(n);

			�ذ� ��� 1. vector <int> �ϳ��� ���� �ű⿡ ���� �� �ְ�, int y�� ���� for������ ���� ������ ���� ��ü�� ������ ���Ϳ� push_back
			�ذ� ��� 2. vector�� ����� ������
		}
	}*/

	//�ذ� ��� 1.
	/*vector <int> temp;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> n;
			temp.push_back(n);
		}
		v.push_back(temp);
		temp.clear();
	}*/

	//�ذ� ��� 2.
	/*v.resize(10);
	for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++) {
			cin >> n;
			v[i].push_back(n);
		}
	}*/

	//������ ���� Ȯ�ο�
	/*for (int i = 0; i < 10; i++) {
		for (int y = 0; y < 10; y++) {
			cout << v[i][y] << " ";
		}
		cout << "\n";
	}*/

	//�׸��� �� ������ ���������� �� �پ� �Է¹޾Ƽ� ���� ����� (��? ��� ���?) �ٷ� �ٷ� ������� 
	//�ٵ� �� ���� ���� �Է� ��찡 ���� ���� ��찡 �ƴ϶� �� �� �پ� �ԷµǴµ�? 
	//�Է� ���� Ƚ���� ����.
	//���� x �� �Ѵٰ� �ϸ� �Ʒ��� �ҽ� �ڵ带 �߰����ָ� ��(247, 248, 249, 268��° �� �ּ� �����ϸ� ��)
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
		ans.resize(10); //resize ����ϸ� ����ִ� �ε��� �κ� 0���� �ʱ�ȭ ��.
		for (int i = 0; i < 10; i++) {
			//���Ϳ� ���� ä������ �� �ڴϱ� �ε����� ������ �� ����.
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
