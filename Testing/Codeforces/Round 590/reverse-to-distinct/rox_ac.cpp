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

const int BITS = 20;
const int MASK = (1 << BITS);

bool bit(int val, int pos) {
    return ((val >> pos) & 1);
}

int cnt(int val) {
    int res = 0;
    for (int pos = 0; pos < BITS; pos++)
        res += bit(val, pos);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = sz(s);

    vector<bool> used(MASK);
    for (int i = 0; i < n; i++) {
        int mask = 0;
        for (int j = 0; i + j < n; j++) {
            int k = (s[i + j] - 'a');
            if (bit(mask, k))
                break;
            mask |= (1 << k);
            used[mask] = true;
        }
    }

    vector<int> dp(MASK);
    for (int mask = 0; mask < MASK; mask++) {
        if (used[mask]) {
            dp[mask] = cnt(mask);
            continue;
        }
        for (int i = 0; i < BITS; i++) {
            if (bit(mask, i))
                dp[mask] = max(dp[mask], dp[mask ^ (1 << i)]);
        }
    }

    int ans = 0;
    for (int mask = 0; mask < MASK; mask++) {
        if (used[mask])
            ans = max(ans, cnt(mask) + dp[mask ^ (MASK - 1)]);
    }

    cout << ans << endl;
}
