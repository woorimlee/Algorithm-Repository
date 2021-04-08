#include <regex>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector <string> banned = { "hit" };

    for (auto& c : paragraph) c = isalpha(c) ? tolower(c) : ' '; // to_lower paragraph

    regex rgx("\\w+");
    smatch sm;
    unordered_map <string, int> cnt_words;

    while (regex_search(paragraph, sm, rgx)) {
        // if key isn't exist in map then map makes defalut value
        vector<string>::iterator it;
        it = find(banned.begin(), banned.end(), sm[0].str());
        if (it != banned.end())
            cout << *it << " ";
        
        
        //    cnt_words[sm[0].str()] += 1;
        paragraph = sm.suffix();
    }

    for (auto it : cnt_words) {
        cout << it.first << " " << it.second << "\n";

    }
    return 0;
}
