#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second

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
    int w, v, u;
};

bool operator <(const Edge& lhs, const Edge& rhs) {
    return lhs.w < rhs.w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        edges.push_back({w, v, u});
    }

    sort(all(edges));
    reverse(all(edges));

    vector<int> ans(n);
    int i = 0;
    while (i < m) {
        int l = i, r = i;
        while (i < m && edges[r].w == edges[l].w) {
            r++;
        }
        
        map<int, int> upd;
        for (int j = l; j < r; j++) {
            auto [w, v, u] = edges[j];
            upd[v] = max(upd[v], ans[u] + 1);
        }

        for (auto [v, val] : upd) {
            ans[v] = max(ans[v], val);
        }

        i = r;
    }

    cout << (*max_element(all(ans))) << endl;
}
