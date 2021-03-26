#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        map<int, int> cnt;
        for (auto x : a) {
            ++cnt[x];
        }

        int mx = 0;
        for (auto [k, v] : cnt) {
            mx = max(mx, v);
        }

        if (mx > n - mx) {
            cout << (2 * mx - n) << endl;
        } else {
            cout << (n % 2) << endl;
        }
    }
}
