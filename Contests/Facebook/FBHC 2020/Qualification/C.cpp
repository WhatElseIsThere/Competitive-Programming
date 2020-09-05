#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n;
        cin >> n;
        vector<int> p(n), h(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i] >> h[i];
        }

        set<int> xs;
        for (int i = 0; i < n; ++i) {
            xs.insert(p[i]);
            xs.insert(p[i] - h[i]);
            xs.insert(p[i] + h[i]);
        }

        unordered_map<int, vector<int>> hs;
        for (int i = 0; i < n; ++i) {
            hs[p[i]].push_back(h[i]);
        }

        int ans = 0;
        unordered_map<int, int> dp;
        for (auto x : xs) {
            for (auto h : hs[x]) {
                dp[x + h] = max(dp[x + h], dp[x] + h);
                dp[x] = max(dp[x], dp[x - h] + h);
            }
            ans = max(ans, dp[x]);
        }

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
