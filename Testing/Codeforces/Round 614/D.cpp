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

const ll INF = 1e18;

ll dist(ll x1, ll y1, ll x2, ll y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll x0, y0, ax, ay, bx, by;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    ll xs, ys, t;
    cin >> xs >> ys >> t;

    vector<ll> px, py;
    while (true) {
        px.push_back(x0);
        py.push_back(y0);

        if (x0 >= INF / ax || y0 >= INF / ay)
            break;

        x0 = x0 * ax + bx;
        y0 = y0 * ay + by;
    }

    int ans = 0;
    int k = sz(px);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            ll d1 = dist(xs, ys, px[i], py[i]);
            ll d2 = dist(px[i], py[i], px[j], py[j]);

            if (d1 + d2 <= t)
                ans = max(ans, abs(j - i) + 1);
        }
    }

    cout << ans << endl;
}
