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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;
        vector<pair<int, int>> points;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            points.emplace_back(x, y);
        }
        points.emplace_back(0, 0);

        sort(all(points));

        bool ok = true;
        string ans;
        for (int i = 1; i <= n; i++) {
            auto cur = points[i];
            auto prv = points[i - 1];

            int dx = cur.fi - prv.fi;
            int dy = cur.se - prv.se;

            if (dy < 0) {
                ok = false;
                break;
            }

            ans += string(dx, 'R');
            ans += string(dy, 'U');
        }
        
        if (ok) {
            cout << "YES" << endl;
            cout << ans << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
