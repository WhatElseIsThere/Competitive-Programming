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

    int q;
    cin >> q;

    while (q--) {
        ll n, m;
        cin >> n >> m;

        int cur = 0;
        vector<int> sum;
        for (int i = 1; i <= 10; i++) {
            cur += (m * i) % 10;
            sum.push_back(cur);
        }

        ll k = n / m;

        if (k == 0) {
            cout << 0 << endl;
            continue;
        }

        ll ans = (k - 1) / 10 * sum.back() + sum[(k - 1) % 10];
        cout << ans << endl;
    }
}
