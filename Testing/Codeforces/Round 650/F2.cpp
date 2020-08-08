#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(a);
        sort(b.begin(), b.end());

        unordered_map<int, int> next_val;
        for (int i = 0; i + 1 < n; ++i) {
            next_val[b[i]] = b[i + 1];
        }
        next_val[b[n - 1]] = INT_MAX;

        unordered_map<int, vector<int>> positions;
        for (int i = 0; i < n; ++i) {
            positions[a[i]].push_back(i);
        }
        positions[INT_MAX].push_back(INT_MIN);

        unordered_map<int, int> cnt;
        vector<int> cnt_right(n);
        for (int i = n - 1; i >= 0; --i) {
            ++cnt[a[i]];
            cnt_right[i] = cnt[a[i]];
        }

        auto pos = [&](int val, int i) {
            const auto& v = positions[val];
            auto it = upper_bound(v.begin(), v.end(), i);
            return it == v.end() ? -1 : *it;
        };

        vector<int> dp1(n, 1), dp2(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            int val = a[i];
            int j1 = pos(val, i);
            int j2 = pos(next_val[val], i);

            // dp1[i]
            if (j1 != -1) {
                dp1[i] = max(dp1[i], dp1[j1] + 1);
            }
            if (j2 != -1) {
                dp1[i] = max(dp1[i], dp2[j2] + 1);
            }

            // dp2[i]
            dp2[i] = cnt_right[i];
            if (i == positions[val][0]) {
                int j3 = pos(next_val[val], positions[val].back());
                if (j3 != -1) {
                    dp2[i] = max(dp2[i], cnt_right[i] + dp2[j3]);
                }
            }
        }

        int max1 = *max_element(dp1.begin(), dp1.end());
        int max2 = *max_element(dp2.begin(), dp2.end());
        int ans = n - max(max1, max2);

        cout << ans << endl;
    }
}
