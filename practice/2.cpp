#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

struct Queue{
    Node* front = nullptr;
    Node* back = nullptr;


    void push(int x){
        Node* temp = new Node(x);

    }
};