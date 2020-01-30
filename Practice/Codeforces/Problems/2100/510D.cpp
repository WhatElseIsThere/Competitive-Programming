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

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void upd(unordered_map<int, int>& dp, int a, int b) {
    if (!dp.count(a) || dp[a] > b)
        dp[a] = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> c(n);
    for (int i = 0; i < n; i++)
        cin >> c[i];

    unordered_map<int, int> dp;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> tr;
        for (auto [val, cost] : dp) {
            int g = gcd(val, a[i]);
            tr.emplace_back(g, cost + c[i]);
        }

        upd(dp, a[i], c[i]);
        for (auto [val, cost] : tr) {
            upd(dp, val, cost);
        }
    }

    int ans = (dp.count(1) ? dp[1] : -1);

    cout << ans << endl;
}
