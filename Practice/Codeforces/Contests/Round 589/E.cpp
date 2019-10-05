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

const int MOD = 1e9 + 7;
const int MAXN = 250;

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return add(a, MOD - b);
}

int mul(int a, int b) {
    return (a * 1LL * b) % MOD;
}

int binPow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = mul(res, a);
        a = mul(a, a);
        n >>= 1;
    }
    return res;
}

int cnk[MAXN + 1][MAXN + 1], pw[MAXN + 1];
int dp[MAXN + 1][MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    for (int i = 0; i <= n; i++) {
        cnk[i][0] = 1;
        for (int j = 1; j <= i; j++)
            cnk[i][j] = add(cnk[i - 1][j - 1], cnk[i - 1][j]);
    }

    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = mul(pw[i - 1], k);

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int p = 1;
            for (int x = j; x >= 1; x--) {
                dp[i][j] = add(dp[i][j], mul(cnk[j][x], mul(p, mul(pw[n - j], dp[i - 1][j - x]))));
                p = mul(p, k - 1);
            }
            if (n - j > 0)
                dp[i][j] = add(dp[i][j], mul(p, mul(sub(pw[n - j], binPow(k - 1, n - j)), dp[i - 1][j])));
        }
    }

    cout << dp[n][n] << endl;
}
