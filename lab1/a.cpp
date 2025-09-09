#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        deque<int> deck;

        // строим порядок с конца
        for (int i = n; i >= 1; i--) {
            // шаг 1: вставляем карту i сверху
            deck.push_front(i);

            // шаг 2: прокручиваем назад i раз
            for (int j = 0; j < i; j++) {
                int x = deck.back();
                deck.pop_back();
                deck.push_front(x);
            }
        }

        // проверка симуляцией вперёд (на всякий случай)
        queue<int> q;
        for (int x : deck) q.push(x);
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int x = q.front();
                q.pop();
                q.push(x);
            }
            if (q.front() != i) {
                ok = false;
                break;
            }
            q.pop();
        }

        if (!ok) {
            cout << -1 << "\n";
        } else {
            for (int i = 0; i < (int)deck.size(); i++) {
                cout << deck[i] << (i + 1 == deck.size() ? '\n' : ' ');
            }
        }
    }
}
