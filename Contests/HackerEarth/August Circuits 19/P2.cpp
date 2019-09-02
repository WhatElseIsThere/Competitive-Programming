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

    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    vector<int> dxTime(2 * n + 1, INT_MAX);
    vector<int> dyTime(2 * m + 1, INT_MAX);
    vector<bool> toPrint(q);

    int x = 0, y = 0;
    for (int i = 0; i < q; i++) {
        int qt;
        cin >> qt;

        if (qt == 1) {
            int dy, dx;
            cin >> dy >> dx;
            dy *= -1, dx *= -1;

            int xx = x + dx, yy = y + dy;
            for (int j = max(min(x, xx), -n); j <= min(max(x, xx), +n); j++)
                dxTime[j + n] = min(dxTime[j + n], i);
            for (int j = max(min(y, yy), -m); j <= min(max(y, yy), +m); j++)
                dyTime[j + m] = min(dyTime[j + m], i);

            x = xx, y = yy;
        } else {
            toPrint[i] = true;
        }
    }

    vector<int> out(q);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '0')
                continue;

            int tm = min(
                min(dxTime[-(i + 1) + n], dxTime[+(n - i) + n]),
                min(dyTime[-(j + 1) + m], dyTime[+(m - j) + m])
            );

            if (tm != INT_MAX)
                out[tm]++;
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cur += (a[i][j] == '1');

    for (int i = 0; i < q; i++) {
        cur -= out[i];
        if (toPrint[i])
            cout << cur << '\n';
    }
}
