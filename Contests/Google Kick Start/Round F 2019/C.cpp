#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

const int MAXN = 1e5;

ll dp[MAXN][2][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<vector<int>> g(n);
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            v--, u--;
            g[v].push_back(u);
            g[u].push_back(v);
        }

        function<void(int, int)> dfs = [&] (int v, int p) {
            for (auto u : g[v]) {
                if (u != p)
                    dfs(u, v);
            }

            vector<int> children;
            for (auto u : g[v]) {
                if (u != p)
                    children.push_back(u);
            }

            if (children.empty()) {
                dp[v][0][0] = 0;
                dp[v][0][1] = LLONG_MIN;
                dp[v][1][1] = a[v];
                return;
            }

            // 0 0
            dp[v][0][0] = 0;
            for (auto u : children)
                dp[v][0][0] += max(dp[u][0][0], dp[u][0][1]);

            // 1 1
            dp[v][1][1] = a[v];
            for (auto u : children) {
                ll x = max(dp[u][0][0] + a[u], dp[u][0][1]);
                ll y = dp[u][1][1];
                dp[v][1][1] += max(x, y);
            }

            // 0 1
            dp[v][0][1] = a[v];

            ll minDiff = LLONG_MAX;
            for (auto u : children) {
                ll x = max(dp[u][0][0], dp[u][0][1]);
                ll y = dp[u][1][1];
                dp[v][0][1] += max(x, y);
                minDiff = min(minDiff, x - y);
            }

            dp[v][0][1] -= max(minDiff, 0LL);
        };

        dfs(0, -1);

        ll ans = max(max(dp[0][0][0], dp[0][0][1]), dp[0][1][1]);

        cout << "Case #" << test << ": " << ans << endl;
    }
}
