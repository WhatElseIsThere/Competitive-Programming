#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define fi first
#define se second

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

const int MAXN = 2e5;

vector<int> g[MAXN];
pair<int, int> val[MAXN];
array<int, 4> ans;

pair<int, int> inc(pair<int, int> p) {
    return make_pair(p.fi + 1, p.se);
}

void dfs1(int v, int p) {
    val[v] = {0, v};
    for (int u : g[v]) {
        if (u != p) {
            dfs1(u, v);
            if (inc(val[u]) > val[v])
                val[v] = inc(val[u]);
        }
    }
}

void dfs2(int v, int p, pair<int, int> up_val) {
    vector<pair<int, int>> vals = {up_val};
    for (int u : g[v]) {
        if (u != p) {
            vals.push_back(inc(val[u]));
        }
    }
    
    if (sz(vals) == 1) {
        return;
    }

    sort(all(vals));
    reverse(all(vals));

    if (sz(vals) == 2) {
        array<int, 4> cur = {vals[0].fi + vals[1].fi, v, vals[0].se, vals[1].se};
        ans = max(ans, cur);
    } else {
        array<int, 4> cur = {vals[0].fi + vals[1].fi + vals[2].fi, vals[0].se, vals[1].se, vals[2].se};
        ans = max(ans, cur);
    }

    for (int u : g[v]) {
        if (u != p) {
            pair<int, int> u_val = (vals[0].se != val[u].se ? inc(vals[0]) : inc(vals[1]));
            dfs2(u, v, u_val);
        }
    }
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

    dfs1(0, -1);
    dfs2(0, -1, {0, 0});

    cout << ans[0] << endl;
    cout << (ans[1] + 1) << ' ' << (ans[2] + 1) << ' ' << (ans[3] + 1) << endl;
}
