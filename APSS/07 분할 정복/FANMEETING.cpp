#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void addTo(vector<int>& a, const vector<int>& b, int k);
void subFrom(vector<int>& a, const vector<int>& b);
vector<int> multiply(const vector<int>& a, const vector<int>& b);
vector <int> karatsuba(const vector<int>& a, const vector<int>& b);

int hug_count(const string& members, const string& fans) {
	int ms = members.size();
	int fs = fans.size();
	vector <int> M(ms, 0);
	vector <int> F(fs, 0);

	for (int i = 0; i < ms; i++)
		M[i] = (members[i] == 'M');
	for (int i = 0; i < fs; i++)
		F[fs-i-1] = (fans[i] == 'M'); //뒤집는것이 핵심입니다.

	/*cout << "멤버 : ";
	for (auto it : M)
		cout << it << " ";
	cout << "\n팬 : ";
	for (auto it : F)
		cout << it << " ";
	cout << "\n곱 결과 : ";*/
	vector <int> MF = karatsuba(M, F);
	/*for (auto it : MF) {
		cout << it << " ";
	}cout << "\n";*/
	int cnt = 0;
	for (int i = ms - 1; i < fs; i++)  //교재 기준 c2위치부터 b5까지
		if (MF[i] == 0)
			cnt++;
	return cnt;
}

int main() {
	int C;
	cin >> C;
	while (C--) {
		string members, fans;
		cin >> members >> fans;
		cout << hug_count(members, fans) << "\n";
	}
	return 0;
}

vector<int> karatsuba(const vector <int>& a, const vector <int>& b) {
	int an = a.size();
	int bn = b.size();
	if (an < bn) return karatsuba(b, a);
	if (an == 0 || bn == 0) return vector<int>();
	if (an <= 50) return multiply(a, b);
	
	int half = an / 2;
	vector <int> a0(a.begin(), a.begin() + half);
	vector <int> a1(a.begin() + half, a.end());
	vector <int> b0(b.begin(), b.begin() + min((int)b.size(), half));
	vector <int> b1(b.begin() + min((int)b.size(), half), b.end());
	
	vector <int> z2 = karatsuba(a1, b1);
	vector <int> z0 = karatsuba(a0, b0);
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);
	vector <int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector <int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half * 2);
	return ret;
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector <int> c(((a.size() - 1) + (b.size() - 1) + 1), 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	return c;
}

void addTo(vector <int>& a, const vector <int>& b, int k) {
	a.resize(max((a.size()), (b.size() + k)));
	for (int i = 0; i < b.size(); i++)
		a[i + k] += b[i];
}

void subFrom(vector<int>& a, const vector<int>& b) {
	for (int i = 0; i < b.size(); i++)
		a[i] -= b[i];
}