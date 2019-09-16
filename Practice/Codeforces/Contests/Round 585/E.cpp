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

const int K = 20;
const int MASK = (1 << K);

bool bit(int val, int pos) {
    return ((val >> pos) & 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    vector<vector<ll>> invCnt(K, vector<ll>(K));
    for (int k1 = 0; k1 < K; k1++) {
        for (int k2 = 0; k2 < K; k2++) {
            if (k1 == k2)
                continue;
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (a[i] == k1)
                    invCnt[k1][k2] += cnt;
                if (a[i] == k2)
                    cnt++;
            }
        }
    }

    vector<ll> dp(MASK, LLONG_MAX);
    dp[0] = 0;
    for (int mask = 0; mask < MASK; mask++) {
        for (int i = 0; i < K; i++) {
            if (bit(mask, i))
                continue;

            int tMask = (mask | (1 << i));

            ll val = 0;
            for (int j = 0; j < K; j++) {
                if (bit(mask, j) || j == i)
                    continue;
                val += invCnt[i][j];
            }

            dp[tMask] = min(dp[tMask], dp[mask] + val);
        }
    }

    cout << dp[MASK - 1] << endl;
}
