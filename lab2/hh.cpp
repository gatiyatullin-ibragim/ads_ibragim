#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int v) : data(v), next(nullptr), prev(nullptr) {}
};

void insert_node(Node*& head, int pos, int val) {
    Node* newNode = new Node(val);
    if (!head || pos == 0) {
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        return;
    }
    Node* cur = head;
    for (int i = 0; i < pos - 1 && cur->next; ++i) cur = cur->next;
    newNode->next = cur->next;
    if (cur->next) cur->next->prev = newNode;
    cur->next = newNode;
    newNode->prev = cur;
}

void remove_node(Node*& head, int pos) {
    if (!head) return;
    Node* cur = head;
    if (pos == 0) {
        head = head->next;
        if (head) head->prev = nullptr;
        delete cur;
        return;
    }
    for (int i = 0; i < pos && cur; ++i) cur = cur->next;
    if (!cur) return;
    if (cur->prev) cur->prev->next = cur->next;
    if (cur->next) cur->next->prev = cur->prev;
    delete cur;
}

void replace_node(Node* head, int pos, int val) {
    Node* cur = head;
    for (int i = 0; i < pos && cur; ++i) cur = cur->next;
    if (cur) cur->data = val;
}

void print_list(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << "\n";
}

void reverse_list(Node*& head) {
    if (!head) return;
    Node* cur = head;
    Node* tmp = nullptr;
    while (cur) {
        tmp = cur->prev;
        cur->prev = cur->next;
        cur->next = tmp;
        cur = cur->prev;
    }
    if (tmp) head = tmp->prev;
}

void clear_all(Node*& head) {
    while (head) {
        Node* nxt = head->next;
        delete head;
        head = nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node* head = nullptr;
    int op;
    while (cin >> op) {
        if (op == 0) {
            print_list(head);
            clear_all(head);
            break;
        }
        if (op == 1) {
            int val, pos; cin >> val >> pos;
            insert_node(head, pos, val);
        } else if (op == 2) {
            int pos; cin >> pos;
            remove_node(head, pos);
        } else if (op == 3) {
            int pos, val; cin >> pos >> val;
            replace_node(head, pos, val);
        } else if (op == 4) {
            print_list(head);
        } else if (op == 5) {
            reverse_list(head);
        }
    }
    return 0;
}
