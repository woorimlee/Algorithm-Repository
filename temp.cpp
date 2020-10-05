#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {

    //solution();
    
    string s = "abcde";
    /*s.insert(1, "F"); //위치 무엇을
    cout << s << "\n";
    s.erase(1, 1); //위치 몇 개
    cout << s << "\n";
    s.erase(3);
    cout << s << "\n";
    s.replace(1, 1, "FGHI"); //위치 몇 개 무엇을
    cout << s << "\n";
    */
    s.erase(s.find('b'), 1);
    cout << s;


    
	return 0;
}