#include<iostream>
#include<algorithm>
using namespace std;

bool is_vowel(char ch){
    return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u';
}


bool comporate(char ch1, char ch2){
    if(is_vowel(ch1) && is_vowel(ch2)) return ch1 < ch2;
    if(!is_vowel(ch1) && !is_vowel(ch2)) return ch1 < ch2;
    if(is_vowel(ch1) && !is_vowel(ch2)) return 1;
    if(!is_vowel(ch1) && is_vowel(ch2)) return 0;
}


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    sort(s.begin(), s.end(), comporate);
    cout << s;
}