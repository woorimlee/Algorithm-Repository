#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TrieNode {
    bool finished;
    unordered_map <char, TrieNode*> child;
    TrieNode() : finished(false) {}
};

class Trie {
private : 
    TrieNode* root = nullptr;
public : 
    Trie() {
        root = new TrieNode();
    }
    
    void Insert(string word) {
        TrieNode* curNode = this->root;
        for (const char ch : word) {
            if (!curNode->child[ch]) // nullptr
                curNode->child[ch] = new TrieNode();
            curNode = curNode->child[ch];
        }
        curNode->finished = true;
    }

    int TypingCnt(string word) {
        TrieNode* curNode = this->root->child[word[0]];
        int ret = 1;
        char temp = word[0];
        
        for (int i = 1; i < word.length(); i++) {
            /*cout << temp << "에서 살펴봄 :\n";
            for (auto it : curNode->child)
                cout << it.first << ", ";
            cout << "finished :" << curNode->finished << "\n";*/

            if (curNode->finished || curNode->child.size() >= 2)
                ret++;
            curNode = curNode->child[word[i]];
            temp = word[i];
        }

        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    while (cin >> N) { 
        vector<string> words(N);
        for (int i = 0; i < N; ++i)
            cin >> words[i];

        Trie* root = new Trie();
        for (int i = 0; i < N; ++i)
            root->Insert(words[i]);

        // 모든 입력 횟수 합
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            // cout << words[i] << " : \n";
            int temp = root->TypingCnt(words[i]);
            sum += temp;
            // cout << temp << "\n==============\n";
        }

        double ans = (double)sum / words.size();
        cout << fixed;
        cout.precision(2);
        cout << ans << "\n";
    }

    return 0;
}