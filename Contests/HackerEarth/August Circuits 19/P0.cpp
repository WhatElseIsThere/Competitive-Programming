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

    int tests;
    cin >> tests;

    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n + 1), b(m + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i];

        vector<int> ans(n + 1, -1);
        for (int i = 1; i <= m; i++) {
            for (int j = i; j <= n; j += i) {
                if (ans[j] == -1 && a[j] <= b[i])
                    ans[j] = i;
            }
        }

        for (int i = 1; i <= n; i++)
            cout << ans[i] << '\n';
    }
}
