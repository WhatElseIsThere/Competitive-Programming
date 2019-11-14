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

const int N = 1000;

vector<int> g[N];
bool used[N];

void dfs(int v, int &cnt) {
    used[v] = true;
    cnt++;
    for (auto u : g[v]) {
        if (!used[u])
            dfs(u, cnt);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    vector<int> cnt;
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cnt.push_back(0);
            dfs(i, cnt.back());
        }
    }

    int k;
    cin >> k;
    vector<pair<int, int>> cars(k);
    for (int i = 0; i < k; i++)
        cin >> cars[i].first >> cars[i].second;

    for (auto c : cnt) {
        int id = -1;
        for (int i = 0; i < sz(cars); i++) {
            if (cars[i].first < c || cars[i].second == 0)
                continue;
            if (id == -1 || (cars[i].first < cars[id].first))
                id = i;
        }

        if (id == -1) {
            cout << 0 << endl;
            return 0;
        }

        cars[id].second--;
    }

    cout << 1 << endl;
}
