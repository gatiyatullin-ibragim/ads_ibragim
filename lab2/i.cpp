#include <iostream>
using namespace std;


struct Node{
    string data;
    Node* prev;
    Node* next;
    Node(string s){
        data = s;
        prev = nullptr;
        next = nullptr;
    }
};

Node* add_front(Node* head)