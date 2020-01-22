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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    for (int j = 0; j < m; j++) {
        map<int, int> row_of;
        for (int i = 0; i < n; i++) {
            int val = i * m + j + 1;
            row_of[val] = i;
        }

        vector<int> shift_cnt(n);
        for (int i = 0; i < n; i++) {
            int val = a[i][j];
            if (row_of.count(val)) {
                int ii = row_of[val];
                int shift = (ii <= i ? (i - ii) : (n - (ii - i)));
                shift_cnt[shift]++;
            }
        }

        int min_val = INT_MAX;
        for (int shift = 0; shift < n; shift++) {
            min_val = min(min_val, shift + (n - shift_cnt[shift]));
        }

        ans += min_val;
    }

    cout << ans << endl;
}
