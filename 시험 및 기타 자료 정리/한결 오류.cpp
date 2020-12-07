#include <iostream>
#include <algorithm>
/*
int ans = 0;
int n;
int arr[10];
using namespace std;

//lev:�� x:��
bool check(int lev, int x)
{
	for (int i = 0; i < lev; i++)
	{
		if (x == arr[i])
		{
			return false;
		}
		else if (abs((lev - i) / (x - arr[i])) == 1)
		{
			return false;
		}
	}
	return true;
}

void dfs(int lev)
{
	if (lev >= n)
	{
		cout << "!\n";
		ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[lev] = i;
		cout << lev << " " << i << " \n";
		if (!check(lev, arr[lev]))
		{
			// cout << "?:" << lev << " " << i << " \n";
			continue;
		}
		dfs(lev + 1); // lev == 0, i == 0
	}
}

int main()
{
	cin >> n;
	dfs(0);
	cout << "ww\n";

	cout << ans;
	return 0;
}
*/
//���� ���� �ڵ�
//�Ʒ��� �� �ڵ�

int ans = 0;
int n;
int arr[10];
using namespace std;

//lev:�� x:��
bool check(int lev, int x)
{
	for (int i = 0; i < lev; i++)
	{
		//cout << "y��ȭ�� : " <<(lev - i)<< "\nx��ȭ�� : " << (x - arr[i]) << "\n";
		if (x == arr[i])
		{
			return false;
		}
		else if (abs(lev - i) == abs(x-arr[i]))
		{
			return false;
		}
	}
	return true;
}

void dfs(int lev)
{
	if (lev >= n)	// n = 8
	{
		cout << "!\n";
		ans++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		arr[lev] = i; //0, 0�� ���� ����
		cout << lev << " " << i << " \n";
		if (!check(lev, arr[lev]))
		{
			//cout << "?:" << lev << " " << i << " \n";
			continue;
		}
		dfs(lev + 1); // lev == 0, i == 0
	}
}

int main()
{
	cin >> n;
	dfs(0);

	cout << ans;
	return 0;
}
