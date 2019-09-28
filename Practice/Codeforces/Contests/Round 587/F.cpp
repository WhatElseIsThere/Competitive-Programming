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
    queue<int> q;

    for (int i = 0; i < min(k, n); i++) {
        if (s[i] == '1')
            q.push(i - k);
    }

    auto f = [&] (int pos) {
        return (pos < 0 ? 0 : dp[pos]);
    };

    for (int i = 0; i < n; i++) {
        dp[i] = f(i - 1) + (i + 1);
        if (i + k < n && s[i + k] == '1')
            q.push(i);

        if (!q.empty() && (q.front() + 2 * k < i))
            q.pop();
        if (!q.empty())
            dp[i] = min(f(i), f(q.front() - 1) + (q.front() + k + 1));
    }

    cout << f(n - 1) << endl;
}
