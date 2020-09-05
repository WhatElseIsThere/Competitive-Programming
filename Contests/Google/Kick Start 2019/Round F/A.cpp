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

const int MAXN = 100;

int dp[MAXN][MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; test++) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (a[j] == a[i]) {
                    b[i] = j;
                    break;
                }
            }
        }

        for (int i = 0; i < n; i++)
            dp[0][0][i] = 1;
        dp[0][0][b[0]] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int c = 0; c < n; c++)
                    dp[i][j][c] = dp[i - 1][j][c] + (c != b[i]);

                if (j == 0)
                    continue;

                int minVal = INT_MAX;
                for (int c = 0; c < n; c++)
                    minVal = min(minVal, dp[i - 1][j - 1][c]);

                for (int c = 0; c < n; c++)
                    dp[i][j][c] = min(dp[i][j][c], minVal + (c != b[i]));
            }
        }

        int ans = INT_MAX;
        for (int i = 0; i <= min(k, n - 1); i++)
            for (int j = 0; j < n; j++)
                ans = min(ans, dp[n - 1][i][j]);

        cout << "Case #" << test << ": " << ans << endl;
    }
}
