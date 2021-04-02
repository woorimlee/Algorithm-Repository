#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	vector<string> vec;
	string s;
	int i;

	cin >> s;
	int str_len = s.size();

	for (i = 0; i < str_len; i++)
	{
		vec.push_back(s);
		s.erase(0, 1);
	}

	sort(vec.begin(), vec.end());

	for (i = 0; i < vec.size(); i++)
		cout << vec[i] << '\n';

	return 0;
}