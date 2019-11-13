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
        ll n;
        cin >> n;
        vector<int> d;
        while (n) {
            d.push_back(n % 3);
            n /= 3;
        }
        d.push_back(0);

        for (int i = sz(d) - 1; i >= 0; i--) {
            if (d[i] == 2) {
                for (int j = i + 1; j < sz(d); j++) {
                    if (d[j] == 0) {
                        d[j] = 1;
                        for (int k = 0; k < j; k++)
                            d[k] = 0;
                        break;
                    }
                }
                break;
            }
        }

        ll ans = 0, pw = 1;
        for (int i = 0; i < sz(d); i++) {
            ans += d[i] * pw;
            pw *= 3;
        }

        cout << ans << endl;
    }
}
