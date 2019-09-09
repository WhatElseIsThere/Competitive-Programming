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

const int BITS = 21;
const int MAX_VAL = (1 << BITS);

bool bit(int val, int pos) {
    return ((val >> pos) & 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> cnt(MAX_VAL);

    function<void(int, int)> dfs = [&] (int mask, int pos) {
        if (cnt[mask] == 2)
            return;
        cnt[mask]++;
        for (int i = pos; i < BITS; i++) {
            if (bit(mask, i))
                dfs(mask ^ (1 << i), i + 1);
        }
    };

    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i <= n - 3) {
            int mask = 0;
            for (int j = BITS - 1; j >= 0; j--) {
                if (!bit(a[i], j) && (cnt[mask | (1 << j)] == 2))
                    mask |= (1 << j);
            }
            ans = max(ans, a[i] | mask);
        }
        dfs(a[i], 0);
    }

    cout << ans << endl;
}
