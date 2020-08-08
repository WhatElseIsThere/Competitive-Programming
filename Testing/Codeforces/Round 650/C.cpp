#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        auto cnt = [&](int l, int r) {
            int w = r - l - 1;
            w -= k;
            return w / (k + 1);
        };

        int ans = 0, prv = -k - 1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ans += cnt(prv, i);
                prv = i;
            }
        }
        ans += cnt(prv, n + k);

        cout << ans << endl;
    }
}
