#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct TrieNode {
    struct TrieNode* child[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) {
            child[i] = NULL;
        }
    }
};

TrieNode* root;

bool searchString(string str) {
    TrieNode* curr = root;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        int idx = str[i] - 'a';
        if (curr->child[idx] == NULL) {
            return false;
        }
        curr = curr->child[idx];
    }
    return curr->isEnd;
}

void insertString(string str) {
    TrieNode* curr = root;
    int n = str.length();
    for (int i = 0; i < n; i++) {
        int idx = str[i] - 'a';
        if (curr->child[idx] == NULL) {
            curr->child[idx] = new TrieNode();
        }
        curr = curr->child[idx];
    }
    curr->isEnd = true;
}

void solve() {
    string s;
    cin >> s;

    root = new TrieNode();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        insertString(str);
    }
    int len = s.length();
    vector<int> dp(len + 1);

    dp[len] = 1;

    for (int i = len - 1; i >= 0; i--) {
        TrieNode* test = root;
        for (int j = i; j < len; j++) {
            int idx = s[j] - 'a';
            if (test->child[idx] == NULL) {
                break;
            }
            test = test->child[idx];
            if (test->isEnd) {
                dp[i] = (dp[i] % mod + dp[j + 1] % mod) % mod;
            }
        }
    }

    cout << dp[0] << endl;
}

int main() {
    solve();
    return 0;
}
