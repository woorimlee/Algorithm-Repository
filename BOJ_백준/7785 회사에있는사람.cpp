#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map <string, bool, greater<string> > rec;	//record
	

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;

	string name;
	string acc_rec; //access record.

	for (int i = 0; i < n; i++) {
		cin >> name;
		cin >> acc_rec;
		if (acc_rec.compare("enter") == 0) { // true == enter
			rec[name] = true;
		}
		else {
			rec[name] = false;
		}
	}


	for (auto it : rec) {
		if (it.second == true)
			cout << it.first << "\n";
	}

}