#include <iostream>
#include <stack>
using namespace std;

int main(){

    stack<int> v1;
    stack<int> v2;

    for(int i=0; i<v1.size(); ++i){
        int a,b;
        cin >> a >> b;
        v1.push(a);
        v2.push(b);
    }

    stack<int> res;

    int a = v1.top() + v2.top();
    v1.pop(); v2.pop();

    while(v1.empty()){
        int a = v1.top() + v2.top();
        v1.pop();
        v2.pop();
        res.push(a);
    }
    while(!res.empty()){
        cout << res.top();
        res.pop();
    }
    
    return 0;
}