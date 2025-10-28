#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<string, string> changeLog;
    set<string> newNicknames;
    
    for (int i = 0; i < n; i++) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;
        changeLog[oldNick] = newNick;
        newNicknames.insert(newNick);
    }
    
    map<string, string> result;
    set<string> visited;
    
    for (auto& entry : changeLog) {
        string original = entry.first;
        
        if (newNicknames.find(original) == newNicknames.end()) {
            string current = original;
            visited.insert(current);
            
            while (changeLog.find(current) != changeLog.end()) {
                string next = changeLog[current];
                if (visited.find(next) != visited.end()) {
                    break;
                }
                current = next;
                visited.insert(current);
            }
            
            result[original] = current;
        }
    }
    
    for (auto& entry : changeLog) {
        string original = entry.first;
        if (visited.find(original) == visited.end()) {
          
            string current = original;
            visited.insert(current);
            
            while (changeLog.find(current) != changeLog.end()) {
                string next = changeLog[current];
                if (visited.find(next) != visited.end()) {
                    break;
                }
                current = next;
                visited.insert(current);
            }
            
            result[original] = current;
        }
    }
    
    cout << result.size() << endl;
    for (auto& entry : result) {
        cout << entry.first << " " << entry.second << endl;
    }
    
    return 0;
}