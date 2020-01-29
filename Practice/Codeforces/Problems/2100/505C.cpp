#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

#define fi first
#define se second

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

#ifdef LOCAL
    #define eprint(x) cerr << #x << " = " << (x) << endl
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprint(x)
    #define eprintf(...)
#endif

const int ISLANDS = 30000;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> treasure(ISLANDS + 1);
    for (int i = 0; i < n; i++) {
        int pos;
        cin >> pos;
        treasure[pos]++;
    }

    vector<unordered_map<int, int>> dp(ISLANDS + 1);
    dp[d][d] = treasure[d];

    int ans = 0;
    for (int i = d; i <= ISLANDS; i++) {
        for (auto [j, val] : dp[i]) {
            ans = max(ans, val);
            for (int k = j - 1; k <= j + 1; k++) {
                if (k > 0 && i + k <= ISLANDS) {
                    dp[i + k][k] = max(dp[i + k][k], val + treasure[i + k]);
                }
            }
        }
    }

    cout << ans << endl;
}

