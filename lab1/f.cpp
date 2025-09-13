#include<bits/stdc++.h>
using namespace std;

bool isprime(int x){
    if(x<=1)return false;
    for(int i=2; i*i<= x; ++i){
        if(x%i==0)return false;
    }
    return true;
}

int main(){ 
    int n;
    cin >> n;

    int prime_number = 0;
    int cnt=0;

    for(int i=0; ;i++){
        if(isprime((i))){
            cnt++;
        }
        if(cnt == n){
            prime_number=i;
            break;
        }
    }
    
    cout << prime_number << endl;
    return 0;
}
