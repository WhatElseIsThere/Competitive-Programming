#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int SIGMA = 26;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i];
        }

        vector<int> cnt(n);
        cnt[n - 1] = 1;
        for (auto x : p) {
            ++cnt[x - 1];
        }

        vector<ll> ans(SIGMA);
        int cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            cur += cnt[i];
            ans[s[i] - 'a'] += cur;
        }

        for (int i = 0; i < SIGMA; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}
