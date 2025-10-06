#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int main() {
    int n;
    cin >> n;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* curr = head;

    for (int i = 1; i < n; i++) {
        cin >> x;
        curr->next = new Node(x);
        curr = curr->next;
    }

    curr = head;
    while (curr && curr->next) {
        Node* del = curr->next;      
        curr->next = del->next;      
        delete del;                  
        curr = curr->next;           
    }

    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
