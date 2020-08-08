#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        map<int, int> cnt;
        for (auto x : a) {
            if (x % k == 0) continue;
            ++cnt[k - x % k];
        }

        if (cnt.empty()) {
            cout << 0 << endl;
            continue;
        }

        int max_val = -1, max_mod = -1;
        for (auto [mod, val] : cnt) {
            if (val >= max_val) {
                max_val = val;
                max_mod = mod;
            }
        }

        long long ans = (max_val - 1) * 1LL * k + max_mod + 1;
        cout << ans << endl;
    }
}
