#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

int main() {
    int N;
    cin >> N;

    int x;
    cin >> x;
    Node* head = new Node(x);
    Node* curr = head;

    for (int i = 1; i < N; i++) {
        cin >> x;
        curr->next = new Node(x);
        curr = curr->next;
    }

    curr = head;
    while (curr && curr->next) {
        Node* del = curr->next;      // нода для удаления
        curr->next = del->next;      // пропускаем её
        delete del;                  // освобождаем память
        curr = curr->next;           // идём дальше
    }

    curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;

    return 0;
}
