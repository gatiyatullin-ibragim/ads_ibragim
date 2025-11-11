#include<iostream>
#include<vector>
using namespace std;

vector<int> prefix_func(string s){
    int n = s.size();
    vector<int> vec(n);

    vec[0] = 0;

    for(int i=1; i<n; ++i){
        int j = vec[i-1];

        while(j > 0 && s[i] != s[j]){
            j = vec[j-1];
        }
        if(s[i] == s[j]) j++;
        vec[i] = j;
    }
    return vec;
}

int kmp(string A, string B){
    int n = A.size();
    int m = B.size();
    
    for(int i=0; i<m; i++){
        bool found = false;
        for(int j=0; j<n; j++){
            if(B[i] == A[j]){
                found = true;
                break;
            }
        }
        if(!found){
            return -1;
        }
    }
    
    vector<int> lps = prefix_func(B);
    
    int max_reps = (m/n)+2;
    
    int i = 0; 
    int j = 0;
    
    while(i<n*max_reps){
        if(A[i%n] == B[j]){
            i++;
            j++;
            
            if(j==m){
                return (i+n-1)/n;  
            }
        }else{
            if(j!=0){
                j=lps[j-1];  
            }else{
                i++;
            }
        }
    }
    
    return -1; 
}



int main(){
    string s1,s2;
    cin >> s1 >> s2;

    int res = kmp(s1,s2);
    cout << res << ' ';


    return 0;
}