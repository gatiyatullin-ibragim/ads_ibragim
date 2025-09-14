#include<bits/stdc++.h>
using namespace std;

struct Queue
    {
        int arr[1000];
        int back = 0;
        int head = 0;

    void push(int x){
        arr[back++] = x;
    }

    void pop(){
        if(!empty()) head++;
    }

    int front(){
        return arr[head];
    }

    bool empty(){
        return head == back;
    }

    };
    
    int main(){

    Queue q;

    q.push(2);
    q.push(3);
    q.push(4);


    while(!q.empty()){
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
