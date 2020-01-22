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

const int MAXX = 4e5;

int cnt[MAXX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, x;
    cin >> q >> x;

    set<pair<int, int>> setik;
    for (int i = 0; i < x; i++)
        setik.insert({0, i});

    while (q--) {
        int y;
        cin >> y;
        y %= x;

        setik.erase({cnt[y], y});
        cnt[y]++;
        setik.insert({cnt[y], y});

        auto p = *setik.begin();
        int ans = x * p.fi + p.se;
        cout << ans << '\n';
    }
}
