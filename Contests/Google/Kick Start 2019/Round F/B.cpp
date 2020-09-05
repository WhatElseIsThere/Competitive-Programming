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

ll calcHash(const vector<int> &v) {
    ll res = 0;
    for (int i = 0; i < sz(v); i++)
        res |= (ll(v[i]) << (10 * i));
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n, s;
        cin >> n >> s;
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            int c;
            cin >> c;
            a[i].resize(c);
            for (int j = 0; j < c; j++)
                cin >> a[i][j];
        }

        unordered_map<ll, int> cnt;
        for (int i = 0; i < n; i++) {
            sort(all(a[i]));
            int m = sz(a[i]);
            for (int mask = 0; mask < (1 << m); mask++) {
                vector<int> vals;
                for (int j = 0; j < m; j++) {
                    if ((mask >> j) & 1)
                        vals.push_back(a[i][j]);
                }
                cnt[calcHash(vals)]++;
            }
        }

        ll ans = 0;
        for (int i = 0; i < n; i++)
            ans += (n - cnt[calcHash(a[i])]);

        cout << "Case #" << test << ": " << ans << endl;
    }
}
