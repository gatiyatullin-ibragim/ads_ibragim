#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

int KMP(const string &text, const string &pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> pi = prefix_function(pattern);
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) j++;
        if (j == m) return i - m + 1;  
    }
    return -1;
}

int min_shift(const string &s1, const string &s2) {
    if (s1.size() != s2.size()) return -1;
    string doubled = s1 + s1;
    int pos = KMP(doubled, s2);
    if (pos == -1 || pos >= s1.size()) return -1;
    return s1.size() - pos;  
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    cout << min_shift(s1, s2) << endl;

    return 0;
}
