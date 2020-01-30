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

    int n, x, y;
    cin >> n >> x >> y;
    
    vector<ll> dp(n + 1);
    deque<pair<ll, int>> q;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + x;
        while (!q.empty() && q.front().se < i)
            q.pop_front();
        if (!q.empty())
            dp[i] = min(dp[i], q.front().fi - i * 1LL * x);

        int pos = 2 * i;
        ll val = dp[i] + y + pos * 1LL * x;
        while (!q.empty() && q.back().fi >= val)
            q.pop_back();
        q.push_back({val, pos});
    }

    cout << dp[n] << endl;
}
