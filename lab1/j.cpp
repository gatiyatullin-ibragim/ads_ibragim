#include<bits/stdc++.h>
using namespace std;

int main(){

    deque<int> dq;

    while(true){
        char a;
        cin >> a;

        if(a == '+'){
            int num;
            cin >> num;
            dq.push_front(num);
        }else if(a == '-'){
            int num;
            cin >> num;
            dq.push_back(num);
        }else if(a == '*'){
            if(dq.empty()){
                cout << "error\n";
            }else {
                int res =0;
                int a1 = dq.front();
                int a2 = dq.back();
                res += a1 + a2;
                cout << res << endl;
                dq.pop_front();
                if(!dq.empty()) dq.pop_back();
            }
        }else if (a == '!'){
            break;
        }
    }


    return 0;
}