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

const int MAXN = 3000;

struct Path {
    int v, u, pv, pu;
};

vector<int> g[MAXN];
int cnt[MAXN][MAXN];
ll dp[MAXN][MAXN];

int dfs(int v, int p) {
    int res = 1;
    for (int u : g[v]) {
        if (u != p)
            res += dfs(u, v);
    }
    return res;
}

void upd(int v, int u, ll val) {
    dp[v][u] = max(dp[v][u], val);
    dp[u][v] = max(dp[u][v], val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    for (int v = 0; v < n; v++) {
        for (int u : g[v]) {
            cnt[v][u] = dfs(u, v);
        }
    }

    vector<Path> paths;
    for (int v = 0; v < n; v++) {
        for (int u : g[v]) {
            dp[v][u] = cnt[v][u] * 1LL * cnt[u][v];
            paths.push_back({v, u, u, v});
        }
    }

    for (int i = 0; i < sz(paths); i++) {
        auto [v, u, pv, pu] = paths[i];

        for (int w : g[v]) {
            if (w == pv)
                continue;
            if (dp[w][u] == 0)
                paths.push_back({w, u, v, pu});
            upd(w, u, dp[v][u] + cnt[v][w] * 1LL * cnt[pu][u]);
        }

        for (int w : g[u]) {
            if (w == pu)
                continue;
            if (dp[v][w] == 0)
                paths.push_back({v, w, pv, u});
            upd(v, w, dp[v][u] + cnt[pv][v] * 1LL * cnt[u][w]);
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
}
