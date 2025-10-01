#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node* insertNode(Node* head, int data, int pos){
    Node* newNode = new Node(data);

    if(pos==0){
        newNode->next=head;
        head=newNode;
        return head;
    }

    Node* current = head;
    for(int i=0; i<pos-1 && current != nullptr; ++i){
        current = current->next;
    }

    newNode->next = current->next;
    current->next =newNode;

    return head;

}

void printlist(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout  << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;
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
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    }

    int data, pos;
    cin >> data >> pos;

    head = insertNode(head,data,pos);

    printlist(head);


    return 0;
}