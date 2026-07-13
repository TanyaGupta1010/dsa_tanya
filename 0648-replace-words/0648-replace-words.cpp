class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }
    void insert(string word) {
        TrieNode* curr = root;
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == nullptr) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
        }
        curr->isEnd = true;
    }
    string findword(string word) {
        TrieNode* curr = root;
        string prefix = "";
        for (char ch : word) {
            int index = ch - 'a';
            if (curr->children[index] == nullptr)
                return word;
            curr = curr->children[index];
            prefix += ch;
            if (curr->isEnd)
                return prefix;
        }
        return word;
    }
};
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        for (string word : dictionary)
            trie.insert(word);
        stringstream ss(sentence);
        string word;
        string ans = "";
        while (ss >> word) {
            ans += trie.findword(word);
            ans += " ";
        }
        ans.pop_back();
        return ans;
    }
};