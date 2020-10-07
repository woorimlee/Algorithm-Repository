#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
���ڸ� �Է¹ް�,
���ĺ� ������ ���� �ͺ��� ū �ͱ���
�ּ� �� ���� ������ �� ���� ������ �����ϴ� ������ L ���� ���ڸ� �̾Ƴ���
(��������� ���� �����ϴ°� �߰� �� ��Ʈ��ŷ�ؼ� �������� �Ѿ�� ...)
����ϴ� ���� ������ �ݺ�.

�̸� ���� ����, ���� ���� �˻��ϴ� �Լ� �ϳ� �߰� (check �Լ�)
��� �Լ� ���� �Լ� �ϳ� �߰�(make_password �Լ�)
*/

string str;
int L, C;

bool check(string test) {
	int consonant = 0;
	int collection = 0;
	for (auto it : test) {
		if (it == 'a' || it == 'e' || it == 'i' || it == 'o' || it == 'u') collection++;
		else consonant++;
	}

	return (collection >=1 && consonant >= 2);
}

int make_password(string word, int count) {

	//1. base case�� ��� �Լ��� ���� ���ڿ� ���̰� L�� ��.
	if (word.length() == L) {
		if (check(word)) {
			cout << word << endl;
		}
		return 0;
	}

	//5. �Ʒ��� ex ��Ȳ���� C�� 6�̰�, count�� 6�� �Ǹ� �ȵǴϱ� return ���� �߰�.
	if (count >= str.length()) return 0;
	//6. 4���� ��й�ȣ�� ����� �� �� �� �ܾ d�� �� �̻� �˻��� �ʿ䰡 ����.
	//   ���� word[0]�� str[3]�̸� return.
	//   str[3]�� 3�� C - L + 1�� ��������.
	if (word[0] == str[C - (L - 1)]) return 0;
	
	//2. ��������� ��ȣ�� ����.
	//ex) abcdef�� �־��� �ܾ���, "" -> "a" -> "ab" -> "abc" -> "abcd" ���� �����ϰ� 1�� ���ǿ� �ɷ��� cout << "abcd"
	make_password(word + str[count], count + 1);
	//3. "abcd" ��� �� return�Ǹ� �� ��ġ�� ���ƿ�. 
	//   �̶� word�� "abc"�� ��Ȳ. "abce"�� ����� ���� count�� +1 ��������, word�� "abc"�� �ѱ��.
	make_password(word, count + 1);
	//4. ���� ��Ȳ�� ��� �����ϸ� ������ "abcf"���� �� ���̰�, �� ������ return ������ ���� ���������Ѵ�. 
	//   (�ٷ� abcf ��� �� abc ���·� �ٽ� ���ƿ��� make_paseword("abc", count + 1) �� ����Ǵµ�, count�� 6�� �Ǹ� �� �ȴ�.)

	return 0;
}

int main(void) {
	cin >> L >> C;

	char temp;
	for (int i = 0; i < C; i++) {
		cin >> temp;
		str += temp;
	}
	sort(str.begin(), str.end());

	make_password("", 0);

	return 0;
}