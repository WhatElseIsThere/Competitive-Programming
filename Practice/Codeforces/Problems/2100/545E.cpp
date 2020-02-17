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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<array<int, 3>>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        v--, u--;
        g[v].push_back({u, w, i});
        g[u].push_back({v, w, i});
    }
    int s;
    cin >> s;
    s--;

    vector<ll> d(n, LLONG_MAX);
    vector<int> p_w(n), p_id(n);
    d[s] = 0;

    set<pair<ll, int>> st;
    for (int v = 0; v < n; v++) {
        st.insert({d[v], v});
    }

    for (int i = 0; i < n; i++) {
        auto it = st.begin();
        int v = it->second;
        st.erase(it);

        for (auto [u, w, id] : g[v]) {
            if (make_pair(d[v] + w, w) < make_pair(d[u], p_w[u])) {
                st.erase({d[u], u});
                d[u] = d[v] + w;
                p_w[u] = w;
                p_id[u] = id;
                st.insert({d[u], u});
            }
        }
    }

    ll ans = 0;
    for (int v = 0; v < n; v++) {
        if (v != s) {
            ans += p_w[v];
        }
    }

    cout << ans << endl;
    for (int v = 0; v < n; v++) {
        if (v != s) {
            cout << (p_id[v] + 1) << ' ';
        }
    }
    cout << endl;
}
