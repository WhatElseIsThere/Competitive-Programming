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

struct Edge {
    int u, v, w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w});
    }
    vector<int> qw(m);
    for (int i = 0; i < m; i++)
        cin >> qw[i];

    vector<pair<int, int>> order;
    for (int i = 0; i < n - 1; i++)
        order.emplace_back(edges[i].w, -1 - i);
    for (int i = 0; i < m; i++)
        order.emplace_back(qw[i], i);
    sort(all(order));

    vector<ll> ans(m);

    vector<int> p(n), cnt(n, 1);
    iota(all(p), 0);

    function<int(int)> find = [&] (int v) {
        return (v == p[v] ? v : (p[v] = find(p[v])));
    };

    auto unite = [&] (int u, int v) {
        u = find(u);
        v = find(v);
        if (cnt[u] < cnt[v])
            swap(u, v);
        p[u] = v;
        cnt[v] += cnt[u];
    };

    ll cur = 0;
    for (auto x : order) {
        int id = x.second;
        if (id < 0) {
            id = -id - 1;
            int u = edges[id].u;
            int v = edges[id].v;
            cur += cnt[find(u)] * 1LL * cnt[find(v)];
            unite(u, v);
        } else {
            ans[id] = cur;
        }
    }

    for (auto x : ans)
        cout << x << ' ';
    cout << endl;
}
