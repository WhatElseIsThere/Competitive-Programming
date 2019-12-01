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

const int K = 26;

bool g[K][K], used[K];

void dfs(int v) {
    used[v] = true;
    for (int u = 0; u < K; u++)
        if (g[v][u] && !used[u])
            dfs(u);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> in(K);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (auto c : s) {
            in[c - 'a'] = true;
            g[c - 'a'][s[0] - 'a'] = true;
            g[s[0] - 'a'][c - 'a'] = true;
        }
    }

    int ans = 0;
    for (int v = 0; v < K; v++) {
        if (!in[v])
            continue;
        if (!used[v]) {
            dfs(v);
            ans++;
        }
    }

    cout << ans << endl;
}
