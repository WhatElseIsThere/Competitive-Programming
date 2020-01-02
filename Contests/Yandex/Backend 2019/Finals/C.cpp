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

const int N = 1e4 + 2;
const int D = 300 + 1;
const int T = 1e9;

int dp[N][D];

void remax(int &a, int b) {
    if (b > a)
        a = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; i++)
        cin >> events[i].first >> events[i].second;
    events.push_back({0, 0});
    events.push_back({T + 100, 0});
    sort(all(events));

    memset(dp, -1, sizeof(dp));

    vector<int> to(n + 1);
    for (int i = 0; i <= n; i++)
        to[i] = lower_bound(all(events), make_pair(events[i].first + events[i].second, -1)) - events.begin();

    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < D; j++) {
            if (dp[i][j] == -1)
                continue;

            int t = events[i + 1].first - events[i].first;
            remax(dp[i + 1][max(j - t, 0)], dp[i][j]);

            if (j <= k) {
                int t = events[to[i]].first - (events[i].first + events[i].second);
                remax(dp[to[i]][max(j + 2 * events[i].second - t, 0)], dp[i][j] + events[i].second);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < D; i++)
        remax(ans, dp[n + 1][i]);

    cout << ans << endl;
}
