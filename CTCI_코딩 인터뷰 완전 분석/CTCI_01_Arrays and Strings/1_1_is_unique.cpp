#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string word;

bool useBoolArray() {
	bool alphabet[128] = { false, };
	
	//To erase unnecessary works.
	if (word.length() > 128) {
		return false;
	}

	for (int i = 0; i < word.length(); i++) {
		if (alphabet[word[i]])
			return false;
		alphabet[word[i]] = true;
	}
	return true;
}

bool useSort() {
	sort(word.begin(), word.end());
	for (int i = 0; i < word.length() - 1; i++) {
		if (word[i] == word[i + 1])
			return false;
	}
	return true;
}

int main(void) {

	cin >> word;

	if (!useBoolArray())
		cout << "Use bool array : This isn't unique.\n";
	else
		cout << "Use bool array : This is unique.\n";

	if (!useSort())
		cout << "Use sort func : This isn't unique.\n";
	else
		cout << "Use sort func : This is unique.\n";


	return 0;
}