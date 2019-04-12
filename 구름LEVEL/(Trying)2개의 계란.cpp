#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int eggDrop(int n, int k)
{
	/* A 2D table where entery eggFloor[i][j] will represent minimum
	   number of trials needed for i eggs and j floors. */
	int eggFloor[3][101];
	int res;
	int i, j, x;

	// We need one trial for one floor and0 trials for 0 floors 
	for (i = 1; i <= n; i++)
	{
		eggFloor[i][1] = 1;
		eggFloor[i][0] = 0;
	}

	// We always need j trials for one egg and j floors. 
	for (j = 1; j <= k; j++)
		eggFloor[1][j] = j;

	// Fill rest of the entries in table using optimal substructure 
	// property 
	for (i = 2; i <= n; i++)
	{
		for (j = 2; j <= k; j++)
		{
			eggFloor[i][j] = INT_MAX;
			for (x = 1; x <= j; x++)
			{
				res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
				if (res < eggFloor[i][j])
					eggFloor[i][j] = res;
			}
		}
	}

	// eggFloor[n][k] holds the result 
	return eggFloor[n][k];
}

/* Driver program to test to pront printDups*/
int main()
{
	int n = 2, k;
	cin >> k;
	cout << eggDrop(n, k);
	return 0;
}