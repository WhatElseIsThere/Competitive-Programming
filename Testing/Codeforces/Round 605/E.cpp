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

const int N = 2e5;

int a[N];
vector<int> g[N];

vector<int> bfs(int n, bool parity) {
    vector<int> d(n, -1);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if ((a[i] & 1) == parity) {
            d[i] = 0;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (auto u : g[v]) {
            if (d[u] == -1) {
                d[u] = d[v] + 1;
                q.push(u);
            }
        }
    }

    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int v = 0; v < n; v++) {
        for (auto u : {v - a[v], v + a[v]}) {
            if (u >= 0 && u < n)
                g[u].push_back(v);
        }
    }

    vector<vector<int>> ans(2);
    ans[0] = bfs(n, 1);
    ans[1] = bfs(n, 0);

    for (int i = 0; i < n; i++)
        cout << ans[a[i] & 1][i] << ' ';
    cout << endl;
}
