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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<int> r(h), c(w);
    for (int i = 0; i < h; i++)
        cin >> r[i];
    for (int i = 0; i < w; i++)
        cin >> c[i];

    vector<vector<int>> grid(h, vector<int>(w, -1));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < r[i]; j++)
            grid[i][j] = 1;
        if (r[i] < w)
            grid[i][r[i]] = 0;
    }

    int ans = 1;
    for (int j = 0; j < w; j++) {
        for (int i = 0; i < c[j]; i++) {
            if (grid[i][j] == 0)
                ans = 0;
            grid[i][j] = 1;
        }
        if (c[j] < h) {
            if (grid[c[j]][j] == 1)
                ans = 0;
            grid[c[j]][j] = 0;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == -1)
                ans = (ans * 2) % MOD;
        }
    }

    cout << ans << endl;
}
