#include <iostream>
#include <vector>
#include <string>

using namespace std;



int main() {

    //solution();
    
    string s = "abcde";
    /*s.insert(1, "F"); //��ġ ������
    cout << s << "\n";
    s.erase(1, 1); //��ġ �� ��
    cout << s << "\n";
    s.erase(3);
    cout << s << "\n";
    s.replace(1, 1, "FGHI"); //��ġ �� �� ������
    cout << s << "\n";
    */
    s.erase(s.find('b'), 1);
    cout << s;


    
	return 0;
}