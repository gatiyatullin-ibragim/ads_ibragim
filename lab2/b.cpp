#include <bits/stdc++.h>
using namespace std;

struct Node {
    string word;
    Node* next;
    Node(string w) : word(w), next(nullptr) {}
};

int main() {
    int N, K;
    cin >> N >> K;

    string w;
    cin >> w;
    Node* head = new Node(w);
    Node* curr = head;

    for (int i=1; i<N; i++){
        cin >> w;
        curr->next = new Node(w);
        curr = curr->next;
    }

    K %= N;
    if (K==0){
        curr = head;
        while (curr){
            cout << curr->word << " ";
            curr = curr->next;
        }
        return 0;
    }

    Node* prev = head;
    for (int i = 1; i < K; i++){
        prev = prev->next;
    }

    Node* newHead = prev->next;

    Node* tail = newHead;
    while (tail->next){
        tail = tail->next;
    }

    tail->next = head;

    prev->next = nullptr;

    curr = newHead;
    while (curr){
        cout << curr->word << " ";
        curr = curr->next;
    }
    cout << "\n";
}
