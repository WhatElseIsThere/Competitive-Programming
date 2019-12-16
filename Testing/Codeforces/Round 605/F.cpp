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

const int N = 200;
const int K = 400;

int dp[N + 1][N + 1][K + 1];
tuple<int, int, int> p[N + 1][N + 1][K + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= N; j++) {
            for (int k = 0; k <= K; k++) {
                dp[i][j][k] = INT_MAX;
                p[i][j][k] = {-1, -1, -1};
            }
        }
    }

    dp[0][0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= K; k++) {
                if (dp[i][j][k] == INT_MAX)
                    continue;
                if (k + 1 <= K)  {  // + '('
                    int kk = k + 1;
                    int ii = i + ((i < n) && (s[i] == '('));
                    int jj = j + ((j < m) && (t[j] == '('));
                    if (dp[ii][jj][kk] > dp[i][j][k] + 1) {
                        dp[ii][jj][kk] = dp[i][j][k] + 1;
                        p[ii][jj][kk] = {i, j, k};
                    }
                }
                if (k - 1 >= 0) {  // + ')'
                    int kk = k - 1;
                    int ii = i + ((i < n) && (s[i] == ')'));
                    int jj = j + ((j < m) && (t[j] == ')'));
                    if (dp[ii][jj][kk] > dp[i][j][k] + 1) {
                        dp[ii][jj][kk] = dp[i][j][k] + 1;
                        p[ii][jj][kk] = {i, j, k};
                    }
                }
            }
        }
    }

    int ansLen = INT_MAX, ansk = -1;
    string ans;

    for (int k = 0; k <= K; k++) {
        if (dp[n][m][k] == INT_MAX)
            continue;
        if (dp[n][m][k] + k < ansLen) {
            ansLen = dp[n][m][k] + k;
            ansk = k;
            ans = string(k, ')');
        }
    }

    int i = n, j = m, k = ansk;
    while (i || j || k) {
        int ii, jj, kk;
        tie(ii, jj, kk) = p[i][j][k];
        ans += (k > kk ? '(' : ')');
        i = ii, j = jj, k = kk;
    }
    reverse(all(ans));

    cout << ans << endl;
}
