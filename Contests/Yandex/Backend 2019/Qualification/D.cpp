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
    int v, u, c;

    bool operator <(const Edge &rhs) const {
        return c < rhs.c;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Edge> edges;
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        edges.push_back({0, i, c});
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        edges.push_back({v, u, c});
    }

    vector<int> p(n + 1);
    iota(all(p), 0);

    function<int(int)> dsuFind = [&] (int v) {
        return (v == p[v] ? v : (p[v] = dsuFind(p[v])));
    };

    auto dsuUnite = [&] (int v, int u) {
        v = dsuFind(v);
        u = dsuFind(u);
        if (rand() & 1)
            swap(v, u);
        p[v] = u;
    };

    ll ans = 0;
    sort(all(edges));
    for (auto e : edges) {
        if (dsuFind(e.v) != dsuFind(e.u)) {
            dsuUnite(e.v, e.u);
            ans += e.c;
        }
    }

    cout << ans << endl;
}
