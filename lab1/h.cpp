    #include<bits/stdc++.h>
    using namespace std;

    bool isprime(int num){
        if(num <= 1) return false;
        for(int i=2; i*i <= num; ++i){
            if(num%i==0)return false;
        }
        return true;
    }


    int main(){
        int n;
        cin >> n;
        if(isprime(n)) cout << "YES";
        else cout << "NO" << endl;

        return 0;
    }
