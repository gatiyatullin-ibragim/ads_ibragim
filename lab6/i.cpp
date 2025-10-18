#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;
    
    vector<int> count(26, 0);
    
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            count[c - 'a']++;
        }
    }
    
    string result = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            result += char('a' + i);
        }
    }
    
    cout << result << endl;
    
    return 0;
}