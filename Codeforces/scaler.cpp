#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool isPalindromePossible(const string& substring, int substitutions) {
    unordered_map<char, int> charCount;

    for (char c : substring) {
        charCount[c]++;
    }

    int oddCount = 0;

    for (const auto& pair : charCount) {
        if (pair.second % 2 != 0) {
            oddCount++;
        }
    }

    // If oddCount is greater than substitutions, it's not possible to form a palindrome.
    return oddCount <= substitutions;
}

vector<string> canRearrangeToPalindrome(const string& s, const vector<tuple<int, int, int>>& queries) {
    vector<string> results;

    for (const auto& query : queries) {
        int start, end, substitutions;
        tie(start, end, substitutions) = query;

        string substring = s.substr(start - 1, end - start + 1);

        if (isPalindromePossible(substring, substitutions)) {
            results.push_back("YES");
        } else {
            results.push_back("NO");
        }
    }

    return results;
}

int main() {
    string s = "cdecd";
    vector<tuple<int, int, int>> queries = {{0,0,0},{0,1,1},{0,2,1},{0,3,0}};

    vector<string> results = canRearrangeToPalindrome(s, queries);

    for (const string& result : results) {
        cout << result << " ";
    }

    cout << endl;

    return 0;
}
