#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while (T--) {
        string line;
        getline(cin, line);

        vector<string> words;
        string word;
        for (char c : line) {
            if (c == ' ') {
                if (!word.empty()) {
                    words.push_back(word);
                    word.clear();
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) words.push_back(word);

        stable_sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        for (int i = 0; i < words.size(); ++i) {
            if (i > 0) cout << " ";
            cout << words[i];
        }
        cout << endl;
    }

    return 0;
}
