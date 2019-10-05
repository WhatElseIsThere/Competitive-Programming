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

void no() {
    cout << -1 << endl;
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    if (m == 0)
        no();

    vector<set<int>> g(n);
    vector<int> s;

    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].insert(u);
        g[u].insert(v);

        if (i == 0) {
            s.push_back(v);
            s.push_back(u);
        }
    }

    for (auto u : g[s[0]]) {
        if (g[s[1]].find(u) != g[s[1]].end()) {
            s.push_back(u);
            break;
        }
    }

    if (sz(s) < 3)
        no();

    vector<int> color(n), cnt(3);
    for (int v = 0; v < n; v++) {
        int c = 0;
        for (int i = 1; i < 3; i++) {
            if (g[v].find(s[i]) == g[v].end())
                c = i;
        }
        color[v] = c;
        cnt[c]++;
    }

    for (int v = 0; v < n; v++) {
        for (auto u : g[v]) {
            if (color[v] == color[u])
                no();
        }
        if (sz(g[v]) < (n - cnt[color[v]]))
            no();
    }

    for (auto c : color)
        cout << (c + 1) << ' ';
    cout << endl;
}
