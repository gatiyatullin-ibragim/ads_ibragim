#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

const long long MOD1 = 1e9 + 7;
const long long MOD2 = 1e9 + 9;
const long long base = 131;

pair<long long, long long> compute_hash(const string &s) {
    long long h1 = 0, h2 = 0;
    for (char c : s) {
        h1 = (h1 * base + c) % MOD1;
        h2 = (h2 * base + c) % MOD2;
    }
    return {h1, h2};
}

vector<pair<long long, long long>> compute_prefix_hashes(const string &s) {
    int n = s.size();
    vector<pair<long long, long long>> hashes(n + 1);
    hashes[0] = {0, 0};
    long long pow1 = 1, pow2 = 1;
    for (int i = 0; i < n; i++) {
        hashes[i + 1].first = (hashes[i].first * base + s[i]) % MOD1;
        hashes[i + 1].second = (hashes[i].second * base + s[i]) % MOD2;
    }
    return hashes;
}

pair<long long, long long> get_subhash(const vector<pair<long long, long long>> &hashes, int l, int r, const vector<long long> &pow1, const vector<long long> &pow2) {
    long long h1 = (hashes[r + 1].first - hashes[l].first * pow1[r - l + 1] % MOD1 + MOD1) % MOD1;
    long long h2 = (hashes[r + 1].second - hashes[l].second * pow2[r - l + 1] % MOD2 + MOD2) % MOD2;
    return {h1, h2};
}

int main() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> tapes(n);
    for (int i = 0; i < n; i++) {
        cin >> tapes[i];
    }

    int len_s = s.size();

    vector<long long> pow1(len_s + 1, 1), pow2(len_s + 1, 1);
    for (int i = 1; i <= len_s; i++) {
        pow1[i] = pow1[i - 1] * base % MOD1;
        pow2[i] = pow2[i - 1] * base % MOD2;
    }

    auto s_hashes = compute_prefix_hashes(s);

    vector<vector<int>> matches(len_s); 
    for (const string &t : tapes) {
        auto t_hash = compute_hash(t);
        int L = t.size();
        for (int i = 0; i + L <= len_s; i++) {
            auto sub_hash = get_subhash(s_hashes, i, i + L - 1, pow1, pow2);
            if (sub_hash == t_hash) {
                matches[i].push_back(L);
            }
        }
    }

    vector<bool> dp(len_s + 1, false);
    dp[0] = true;

    for (int i = 0; i < len_s; i++) {
        if (dp[i]) {
            for (int L : matches[i]) {
                if (i + L <= len_s) {
                    dp[i + L] = true;
                }
            }
        }
    }

    if (dp[len_s]) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}