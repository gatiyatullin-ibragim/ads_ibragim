#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> prefix_function(const string &s) {
    int n = s.length();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

set<int> find_occurrences(const string &text, const string &pattern) {
    string combined = pattern + '#' + text;
    vector<int> pi = prefix_function(combined);
    int pattern_len = pattern.length();
    set<int> occurrences;
    
    for (int i = pattern_len + 1; i < combined.length(); i++) {
        if (pi[i] == pattern_len) {
            int pos = i - 2 * pattern_len;
            occurrences.insert(pos);
        }
    }
    return occurrences;
}

int main() {
    
    string s1, s2, t;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, t);
    
    set<int> occ1 = find_occurrences(s1, t);
    set<int> occ2 = find_occurrences(s2, t);
    
    int count = 0;
    for (int pos : occ1) {
        if (occ2.find(pos) != occ2.end()) {
            count++;
        }
    }
    
    cout << count << "\n";
    
    return 0;
}