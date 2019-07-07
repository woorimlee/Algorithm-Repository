#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;

//최소 이동을 통한 퍼즐 맞추기
//현재 상태에서 1의 비용을 들여 바꿀 수 있는 모든 경우의 수를 큐에 저장하고,
//저장 된 큐에 있는 것을 하나씩 빼내며 다시 1의 비용을 들여 바꿀 수 있는 모든 경우의 수를 큐에 저장하고
//... 위 과정을 반복하여 목적지에 도달하는데 드는 비용을 출력. (BFS 개념)

//이차원 배열을 사용해서 문제를 해결해도 되지만, 
//큐에 저장하며 BFS검사를 할 때 편의성을 위해서 String & int로 바꿔서 계산하려고 함.
//따라서 0 ~ 8까지 숫자를 입력받을 것인데, 계산하기 쉽게 0을 9로 바꿈. 즉, 1 ~ 9까지를 입력받는 것이고
//012345678이 아닌 123456789의 상태를 만드는게 목적.
//숫자 하나씩 입력 받을 때마다 이전 숫자에 *10 해서 값을 늘림.
//ex) 예제 입력처럼 1 0 3 4 2 5 7 8 6을 입력 받는다면
//    최종적으로 103425786으로 int 값을 저장함.

int main()
{
	ios::sync_with_stdio(false);

	int start = 0, temp = 0; //초기 배열 생성
	int now_num, location, new_num;	//while문 안에서 쓸 것
	int direct[4][2] = { { -1, 0 },{ 0, -1 },{ 1, 0 },{ 0, 1 } };
	string now_str;
	queue<int> q;
	unordered_map<int, int> ma;

	for (int i = 0; i < 9; i++) {
		cin >> temp;
		if (temp == 0) {
			temp = 9;
		}
		start = start * 10 + temp;
	}

	//BFS 시작
	q.push(start);
	ma[start] = 0;
	while (!q.empty())
	{
		now_num = q.front(); q.pop();
		now_str = to_string(now_num);

		//0이(9로 바꾼 값) 위치한 index를 찾아서
		location = now_str.find('9');
		//2차원 배열이라고 가정했기 때문에 x와 y좌표 값을 구하고
		int x = location % 3;
		int y = location / 3;

		//네 방향을 검사할 것임. 
		//현재 상태에서 0만 위치를 바꿔가며 BFS를 하면 답을 구할 수 있기 때문에.
		for (int i = 0; i < 4; i++)
		{
			//0이 있는 위치를 상하좌우 이동 가능한 지 검사.(x와 y는 3x3 배열에서 움직임)
			if (0 <= x + direct[i][0] && x + direct[i][0] < 3 &&
				0 <= y + direct[i][1] && y + direct[i][1] < 3) {
				int new_x = x + direct[i][0];
				int new_y = y + direct[i][1];
				string new_str = now_str;
				swap(new_str[y * 3 + x], new_str[new_y * 3 + new_x]);
				new_num = stoi(new_str);

				//이전에 검사한 값이 아니라면(처음 검사한 값이라면).
				if (ma.count(new_num) == 0)
				{
					ma[new_num] = ma[now_num] + 1;
					q.push(new_num);
				}
			}
		}
	}

	//모~~~든 검사가 끝난 뒤, 초기 상태에서 123456789까지 도달하는데 드는 최소 비용 값을 출력.
	if (ma.count(123456789) == 0)
		cout << "-1" << "\n";
	else
		cout << ma[123456789] << "\n";

	return 0;
}