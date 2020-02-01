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

const int MAXN = 1000;

int a[MAXN][MAXN];

vector<ll> calc(const vector<int>& vals, int k, int dec) {
    vector<ll> res = {0};
    priority_queue<ll> q(all(vals));
    for (int i = 1; i <= k; i++) {
        ll val = q.top();
        q.pop();
        res.push_back(res.back() + val);
        q.push(val - dec);
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, p;
    cin >> n >> m >> k >> p;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> row_sum(n), col_sum(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row_sum[i] += a[i][j];
            col_sum[j] += a[i][j];
        }
    }

    auto r = calc(row_sum, k, m * p);
    auto c = calc(col_sum, k, n * p);

    ll ans = LLONG_MIN;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, r[i] + c[k - i] - (i * 1LL * (k - i) * 1LL * p));
    }

    cout << ans << endl;
}
