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

const int N = 100 + 1;

int dp[N][N][N][2];

void remin(int& a, int b) {
    if (b < a)
        a = b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int evenLeft = n / 2, oddLeft = (n + 1) / 2;

    for (auto x : p) {
        if (x != 0) {
            if (x & 1)
                oddLeft--;
            else
                evenLeft--;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                for (int l = 0; l < 2; l++)
                    dp[i][j][k][l] = INT_MAX;

    dp[0][evenLeft][oddLeft][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= evenLeft; j++) {
            for (int k = 0; k <= oddLeft; k++) {
                for (int l = 0; l < 2; l++) {
                    if (dp[i][j][k][l] == INT_MAX)
                        continue;

                    if (p[i] != 0) {
                        int cost = (i == 0 ? 0 : (l ^ (p[i] & 1)));
                        remin(dp[i + 1][j][k][p[i] & 1], dp[i][j][k][l] + cost);
                    }

                    if (j > 0) {
                        int cost = (i == 0 ? 0 : l);
                        remin(dp[i + 1][j - 1][k][0], dp[i][j][k][l] + cost);
                    }

                    if (k > 0) {
                        int cost = (i == 0 ? 0 : (l ^ 1));
                        remin(dp[i + 1][j][k - 1][1], dp[i][j][k][l] + cost);
                    }
                }
            }
        }
    }

    int ans = min(dp[n][0][0][0], dp[n][0][0][1]);
    cout << ans << endl;
}
