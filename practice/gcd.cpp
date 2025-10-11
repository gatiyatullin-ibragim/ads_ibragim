#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
    for(int i = min(a,b); i >= 1; i--){
        if(a%i==0 && b%i==0){
            return i;
        }
    }
    return 1;
}

int gcd_euclide(int a, int b){
    while(b!=0){
        int t = b;
        b = a%b;
        a = t;
    }
    return a;
}



int main(){

    cout << gcd_euclide(34,17);


    return 0;
}