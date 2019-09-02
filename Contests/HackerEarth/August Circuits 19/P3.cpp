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

const int BITS = 30;

int solve(int a, int b, int c) {
    int res = a ^ b;

    for (int i = 0; i < BITS; i++) {
        if ((c >> i) & 1)
            res |= (1 << i);
    }

    if (res == (a ^ b)) {
        for (int i = 0; i < BITS; i++) {
            if ((c >> i) & 1) {
                res ^= (1 << i);
                break;
            }
        }
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += solve(a[i], b[i], c[i]);

    cout << ans << endl;
}
