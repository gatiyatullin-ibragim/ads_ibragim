#include <iostream>
#include <string>
using namespace std;

struct Node {
    string book;
    Node* next;
    Node* prev;
    Node(string b) : book(b), next(nullptr), prev(nullptr) {}
};

struct DoublyLinkedList {
    Node* head;
    Node* tail;
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void add_front(const string& book) {
        Node* node = new Node(book);
        if (!head) head = tail = node;
        else {
            node->next = head;
            head->prev = node;
            head = node;
        }
        cout << "ok\n";
    }

    void add_back(const string& book) {
        Node* node = new Node(book);
        if (!tail) head = tail = node;
        else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
        cout << "ok\n";
    }

    void erase_front() {
        if (!head) {
            cout << "error\n";
            return;
        }
        cout << head->book << "\n";
        Node* tmp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete tmp;
    }

    void erase_back() {
        if (!tail) {
            cout << "error\n";
            return;
        }
        cout << tail->book << "\n";
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete tmp;
    }

    void front() {
        if (!head) {
            cout << "error\n";
            return;
        }
        cout << head->book << "\n";
    }

    void back() {
        if (!tail) {
            cout << "error\n";
            return;
        }
        cout << tail->book << "\n";
    }

    void clear() {
        Node* cur = head;
        while (cur) {
            Node* nx = cur->next;
            delete cur;
            cur = nx;
        }
        head = tail = nullptr;
        cout << "ok\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    DoublyLinkedList list;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "add_front") {
            string book; cin >> book;
            list.add_front(book);
        } else if (cmd == "add_back") {
            string book; cin >> book;
            list.add_back(book);
        } else if (cmd == "erase_front") {
            list.erase_front();
        } else if (cmd == "erase_back") {
            list.erase_back();
        } else if (cmd == "front") {
            list.front();
        } else if (cmd == "back") {
            list.back();
        } else if (cmd == "clear") {
            list.clear();
        } else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
    return 0;
}
