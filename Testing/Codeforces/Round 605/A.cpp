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
        int a, b, c;
        cin >> a >> b >> c;

        int ans = INT_MAX;
        for (int i = a - 1; i <= a + 1; i++) {
            for (int j = b - 1; j <= b + 1; j++) {
                for (int k = c - 1; k <= c + 1; k++) {
                    ans = min(ans, abs(i - j) + abs(i - k) + abs(j - k));
                }
            }
        }

        cout << ans << endl;
    }
}
