#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> boris, nursik;

    for (int i = 0; i < 5; ++i) {
        int n;
        cin >> n;
        boris.push(n);
    }
    for (int i = 0; i < 5; ++i) {
        int m;
        cin >> m;
        nursik.push(m);
    }

    int moves = 0;
    while (!boris.empty() && !nursik.empty() && moves <= 1000000) {
        moves++;

        int a = boris.front(); boris.pop();
        int b = nursik.front(); nursik.pop();

        if ((a == 0 && b == 9) || (a > b && !(a == 9 && b == 0))) {
            // Побеждает Борис
            boris.push(a);
            boris.push(b);
        } else {
            // Побеждает Нурсик
            nursik.push(a);
            nursik.push(b);
        }
    }

    if (moves > 1000000) {
        cout << "blin nichya";
    } else if (boris.empty()) {
        cout << "Nursik " << moves;
    } else {
        cout << "Boris " << moves;
    }

    return 0;
}
