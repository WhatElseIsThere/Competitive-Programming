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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<ll> dp(n);
    set<pair<ll, int>> upd;

    for (int i = 0; i < min(k, n); i++) {
        if (s[i] == '1')
            upd.insert({i + 1, i + k});
    }

    for (int i = 0; i < n; i++) {
        dp[i] = (i ? dp[i - 1] : 0) + (i + 1);
        if (i + k < n && s[i + k] == '1')
            upd.insert({(i ? dp[i - 1] : 0) + (i + k + 1), i + 2 * k});

        while (!upd.empty() && (upd.begin()->second < i))
            upd.erase(upd.begin());
        if (!upd.empty())
            dp[i] = min(dp[i], upd.begin()->first);
    }

    cout << dp[n - 1] << endl;
}
