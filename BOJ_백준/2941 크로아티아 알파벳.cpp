#include <iostream>
#include <string>

using namespace std;

int main() {
	int ans = 0;
	string str;
	cin >> str;

	//생각보다 예외처리가 많았음.
	//스택을 쓰는게 훨씬 코드는 깔끔할 것 같음.
	for (int i = 0; i < str.length(); i++) {
		//(i-1) >= 0은 안 해줘도 될 것 같은데 혹시몰라서 해줌
		if (str[i] == '-' && (i - 1) >= 0) {
			//c- || d-인 경우 c나 d일때 이미 단어 수를 1 증가시켰으니 아무것도 안하고 다음 단어 검사시작
			if (str[i - 1] == 'c' || str[i - 1] == 'd')
				continue;
		}
		else if (str[i] == '=' && (i - 1) >= 0) {
			if (str[i - 1] == 'c' || str[i - 1] == 's')
				continue;
			//dz=먼저 검사하고 z=을 검사해야함.
			else if ((i - 2) >= 0 && str[i - 1] == 'z' && str[i - 2] == 'd') {
				ans--;
				continue;
			}	
			else if (str[i - 1] == 'z')
				continue;
		}
		//j는 그냥 단어일수도 있으니 앞의 단어까지 한 번에 같이 검사해야함
		else if (str[i] == 'j' && (i - 1) >= 0 && (str[i - 1] == 'l' || str[i - 1] == 'n')) {
				continue;
		}
		//기본적으로 모든 단어를 하나씩 취급하는데, 만약 변경된 크로아티아 알파벳이면 위의 if ~ else if 구문을 실행함
		else
			ans++;
	}
	cout << ans;
	return 0;
}