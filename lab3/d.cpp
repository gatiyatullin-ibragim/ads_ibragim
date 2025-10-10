#include <bits/stdc++.h>
using namespace std;

const int MAXVAL = 1000000;
const int MAXN = 100005;

int n, q;
int a[MAXN];

struct Fenwick {
    vector<int> bit;
    int n;
    Fenwick(int n) : n(n), bit(n + 2, 0) {}
    void update(int idx, int delta) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += delta;
    }
    int query(int idx) {
        int res = 0;
        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];
        return res;
    }
    int range_sum(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

int count_value[MAXN];
int overlap[MAXN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> freq(MAXVAL + 1, 0);
    for (int i = 1; i <= n; i++) {
        freq[a[i]]++;
    }
    Fenwick pre(MAXVAL);
    for (int v = 1; v <= MAXVAL; v++) {
        pre.update(v, freq[v]);
    }

    vector<tuple<int, int, int>> queries_by_r2[MAXN + 1];
    vector<tuple<int, int, int>> queries_by_l2m1[MAXN + 1];

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        count_value[i] = pre.range_sum(l1, r1);
        queries_by_r2[r2].emplace_back(l1, r1, i);
        if (l2 - 1 >= 0)
            queries_by_l2m1[l2 - 1].emplace_back(l1, r1, i);
    }

    Fenwick fenw(MAXVAL);
    for (int k = 0; k <= n; k++) {
        if (k >= 1) {
            fenw.update(a[k], 1);
        }
        for (auto [l1, r1, idx] : queries_by_r2[k]) {
            overlap[idx] += fenw.range_sum(l1, r1);
        }
        for (auto [l1, r1, idx] : queries_by_l2m1[k]) {
            overlap[idx] -= fenw.range_sum(l1, r1);
        }
    }

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
    }

    return 0;
}