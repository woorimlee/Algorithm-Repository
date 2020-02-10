#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void normalize(vector<int> &num);
vector<int> multiply(const vector<int> &a, const vector<int> &b);

// a+= b *(10^k);
void addTo(vector <int> &a, const vector <int> &b, int k);

// a -= b;   (a >= b)
void subFrom(vector<int> &a, const vector<int> &b);

vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
	int an = a.size();
	int bn = b.size();

	if (an < bn) return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();
	
	if (an <= 2) return multiply(a, b);

	int half = an / 2;

	/*
		a * b = (a1 * b1 * 10^256)				--> z2
				+ ((a1*b0 + a0*b1) * 10^128)	--> z1
				+ (a0 * b0)						--> z0
				*/
	
	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min((int)b.size(), half));
	vector<int> b1(b.begin() + min((int)b.size(), half), b.end());

	//z2 = a1*b1
	vector<int> z2 = karatsuba(a1, b1);
	//z0 = a0*b0
	vector<int> z0 = karatsuba(a0, b0);
	//a0 <= a0+a1
	addTo(a0, a1, 0);
	//b0 <= b0+b1
	addTo(b0, b1, 0);
	//z1 = (a0*b0) - z0 - z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	//ret = a * b
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;
}

int main() {

	vector <int> a;
	a.push_back(6);
	a.push_back(5);
	a.push_back(4);
	vector <int> b;
	b.push_back(3);
	b.push_back(2);
	b.push_back(1);

	vector <int> ret = karatsuba(a, b);
	for (int i = ret.size() - 1; i >= 0; i--) {
		cout << ret[i];
	}

	return 0;
}

void normalize(vector<int> &num) {
	num.push_back(0);

	for (int i = 0; i + 1 < num.size(); i++) // i+1을 계산하기 때문에 num.size()보다 i+1이 작게
	{
		if (num[i] < 0)	{
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
		}

		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		} 
	}

	while (num.size() > 1 && num.back() == 0)
		num.pop_back();
	return;
}

vector<int> multiply(const vector<int> & a, const vector<int> &b) {
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}
	normalize(c);
	return c;
}


void addTo(vector <int> &a, const vector <int> &b, int k) {
	
	a.resize(max((a.size() + 1), (b.size() + k)));

	for (int i = 0; i < b.size(); i++) {
		a[i + k] += b[i];
	}

	normalize(a);
}

void subFrom(vector<int> &a, const vector<int> &b) {
	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
	normalize(a);
}