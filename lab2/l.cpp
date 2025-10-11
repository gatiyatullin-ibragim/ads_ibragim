#include<iostream>
using namespace std;


struct Node{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};


int maxSubarraySum(Node* head){
    if(!head) return 0;

    int curr_sum = head->val;

    int max_sum = head->val;
    Node* curr = head->next;


    while(curr){
        curr_sum = max(curr->val, curr_sum + curr->val);
        max_sum =  max(max_sum, curr_sum);
        curr = curr->next;
    }

    return max_sum;

}

int main(){

    int n;
    cin >> n;

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        Node* newNode = new Node(x);
        if(!head) head = newNode;
        else tail->next = newNode;
        tail = newNode;
    }

    cout << maxSubarraySum(head) << endl;

    return 0;
}