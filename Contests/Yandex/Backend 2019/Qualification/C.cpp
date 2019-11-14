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
const int R = 180;
const int T0 = 600;
const int T = T0 + R;

vector<pair<int, int>> gr[N];
int color[T + 1][N];

void dfs(int t, int v, int c) {
    color[t][v] = c;
    for (auto e : gr[v]) {
        int u = e.first, w = e.second;
        if (t - w >= 0 && color[t - w][u] == -1)
            dfs(t - w, u, c);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        gr[u].push_back({v, w});
    }

    int s, t0;
    cin >> s >> t0;

    memset(color, -1, sizeof(color));
    for (int c = t0; c <= t0 + R; c++)
        dfs(c, s, c);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        cout << color[0][v] << endl;
    }
}
