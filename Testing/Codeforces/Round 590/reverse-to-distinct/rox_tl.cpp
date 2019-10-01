#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")

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

    vector<int> cnt(MASK);
    for (int mask = 0; mask < MASK; mask++) {
        for (int pos = 0; pos < BITS; pos++)
            cnt[mask] += bit(mask, pos);
    }

    int ans = 0;
    for (int mask = 0; mask < MASK; mask++) {
        if (used[mask]) {
            int val = 0;
            int rmask = (mask ^ (MASK - 1));
            for (int m = rmask; m > (1 << val); m = (m - 1) & rmask) {
                if (used[m] && cnt[m] > val)
                    val = cnt[m];
            }
            ans = max(ans, cnt[mask] + val);
        }
    }

    cout << ans << endl;
}
