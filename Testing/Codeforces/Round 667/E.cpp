#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    while (tcs--) {
        int n, k;
        cin >> n >> k;
        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> y[i];
        }

        sort(x.begin(), x.end());

        vector<int> suff_best(n + 1);
        suff_best[n - 1] = 1;
        for (int l = n - 2, r = n - 1; l >= 0; --l) {
            while (x[r] - x[l] > k) --r;
            suff_best[l] = max(suff_best[l + 1], r - l + 1);
        }

        int ans = 1 + suff_best[1], pref_best = 1;
        for (int r = 1, l = 0; r < n; ++r) {
            while (x[r] - x[l] > k) ++l;
            pref_best = max(pref_best, r - l + 1);
            ans = max(ans, pref_best + suff_best[r + 1]);
        }

        cout << ans << endl;
    }
}
