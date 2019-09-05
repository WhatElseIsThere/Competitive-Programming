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

    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<vector<bool>> b1(n, vector<bool>(m));
    b1[0][0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '#')
                continue;
            if (i > 0 && b1[i - 1][j])
                b1[i][j] = true;
            if (j > 0 && b1[i][j - 1])
                b1[i][j] = true;
        }
    }

    vector<vector<bool>> b2(n, vector<bool>(m));
    b2[n - 1][m - 1] = true;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] == '#')
                continue;
            if (i + 1 < n && b2[i + 1][j])
                b2[i][j] = true;
            if (j + 1 < m && b2[i][j + 1])
                b2[i][j] = true;
        }
    }

    vector<int> cnt(n + m - 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cnt[i + j] += (b1[i][j] && b2[i][j]);

    int ans = *min_element(cnt.begin() + 1, cnt.end() - 1);

    cout << ans << endl;
}
