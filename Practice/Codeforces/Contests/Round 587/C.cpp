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

bool isIn(int x, int y, int rx1, int ry1, int rx2, int ry2) {
    return ((x >= rx1 && x <= rx2) && (y >= ry1 && y <= ry2));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;
    int x5, y5, x6, y6;
    cin >> x5 >> y5 >> x6 >> y6;

    x1 *= 2, y1 *= 2, x2 *= 2, y2 *= 2;
    x3 *= 2, y3 *= 2, x4 *= 2, y4 *= 2;
    x5 *= 2, y5 *= 2, x6 *= 2, y6 *= 2;

    bool ans = false;

    for (int x = x1; x <= x2; x++) {
        ans |= !(isIn(x, y1, x3, y3, x4, y4) || isIn(x, y1, x5, y5, x6, y6));
        ans |= !(isIn(x, y2, x3, y3, x4, y4) || isIn(x, y2, x5, y5, x6, y6));
    }

    for (int y = y1; y <= y2; y++) {
        ans |= !(isIn(x1, y, x3, y3, x4, y4) || isIn(x1, y, x5, y5, x6, y6));
        ans |= !(isIn(x2, y, x3, y3, x4, y4) || isIn(x2, y, x5, y5, x6, y6));
    }

    cout << (ans ? "YES" : "NO") << endl;
}
