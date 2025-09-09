#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> v(n), ans(n);

    stack<int> st;

    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        v[i]=a;
    }


    for(int i=0; i<n; i++){
        while(!st.empty() && v[st.top()] >= v[i]){
            st.pop();
        }

        if(st.empty()) ans[i]=-1;
        else ans[i] = v[st.top()];
        st.push(i);
    }

    for(int i=0; i<n; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}