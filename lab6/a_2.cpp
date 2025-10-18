#include<iostream>
using namespace std;

bool is_vowel(char c){
    return c=='a'|| c=='e'|| c=='u'|| c=='o'|| c=='i';
}

bool comporate(char ch1, char ch2){
    if(is_vowel(ch1) && is_vowel(ch2)) return ch1 < ch2;
    if(!is_vowel(ch1) && !is_vowel(ch2)) return ch1 < ch2;
    if(is_vowel(ch1) && !is_vowel(ch2)) return 1;
    if(!is_vowel(ch1) && is_vowel(ch2)) return 0;
}

string sorting(string s) {
    for (int i = 0; i < s.length(); ++i) {
        for (int j = 0; j < s.length() - i - 1; ++j) {
            if (!comporate(s[j], s[j + 1])) {
                swap(s[j], s[j + 1]);
            }
        }
    }
    return s;
}


int main(){

    int n ;
    cin >> n;
    string s;
    cin >> s;

    cout << sorting(s);

    
    return 0;   
}