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

const int MAXN = 1e5;

bool a[2][MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    int cntV = 0, cntD = 0;

    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        int delta = (a[x][y] ? -1 : +1);
        a[x][y] ^= 1;

        if (a[x ^ 1][y])
            cntV += delta;
        if (y > 0 && a[x ^ 1][y - 1])
            cntD += delta;
        if (y + 1 < n && a[x ^ 1][y + 1])
            cntD += delta;

        bool ans = (cntV == 0 && cntD == 0);

        cout << (ans ? "YES" : "NO") << endl;
    }
}
