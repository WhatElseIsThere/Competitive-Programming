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

const int M = 1000 + 1;
const int N = 100 + 1;

int a[M][N];
ll prefSum[M][N];

ll sum(int i, int j1, int j2) {
    return prefSum[i][j2] - prefSum[i][j1 - 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k, m, n;
    cin >> k >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            prefSum[i][j] = prefSum[i][j - 1] + a[i][j];

    ll ans = LLONG_MIN;
    for (int j1 = 1; j1 <= n; j1++) {
        for (int j2 = j1; j2 <= n; j2++) {
            vector<ll> vals = {0};
            for (int i = 1; i <= m; i++)
                vals.push_back(vals.back() + sum(i, j1, j2));

            int w = k / (j2 - j1 + 1);
            if (w == 0)
                continue;

            deque<pair<ll, int>> q;
            q.push_back({0, 0});
            for (int i = 1; i <= m; i++) {
                while (!q.empty() && q.back().first >= vals[i])
                    q.pop_back();
                q.push_back({vals[i], i});
                while (q.front().second < i - w)
                    q.pop_front();
                ans = max(ans, vals[i] - q.front().first);
            }
        }
    }

    cout << ans << endl;
}
