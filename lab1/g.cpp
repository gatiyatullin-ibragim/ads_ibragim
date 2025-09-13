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

    int super_prime_number = 0;
    int cnt=0;
    int idx=0;

    for(int i=0; ;i++){
        if(isprime(i)){
            idx++;
            if(isprime(idx)){
                cnt++;
            }
        }
        if(cnt == n){
            super_prime_number=i;
            break;
        }
    }
    
    cout << super_prime_number << endl;
    return 0;
}
