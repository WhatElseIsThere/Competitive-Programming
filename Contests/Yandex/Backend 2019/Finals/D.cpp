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

const int N = 1e4;

vector<pair<int, int>> gr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> b(n);
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<int> pos(k);
    for (int i = 0; i < k; i++) {
        cin >> pos[i];
        pos[i]--;
    }
    for (int i = 0; i < m; i++) {
        int w, v, u;
        cin >> w >> v >> u;
        v--, u--;
        gr[u].push_back({v, w});
    }

    set<pair<int, int>> s;
    for (int i = 0; i < n; i++)
        s.insert({-b[i], i});

    while (!s.empty()) {
        int v = s.begin()->second;
        s.erase(s.begin());
        for (auto e : gr[v]) {
            int u = e.first, w = e.second;
            if (b[v] - w > b[u]) {
                s.erase(s.find({-b[u], u}));
                b[u] = b[v] - w;
                s.insert({-b[u], u});
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < k; i++)
        ans += b[pos[i]];

    cout << ans << endl;
}
