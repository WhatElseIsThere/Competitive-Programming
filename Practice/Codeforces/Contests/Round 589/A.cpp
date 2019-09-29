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

    int l, r;
    cin >> l >> r;

    int ans = -1;
    for (int i = l; i <= r; i++) {
        vector<int> v;
        set<int> s;

        int x = i;
        while (x) {
            v.push_back(x % 10);
            s.insert(x % 10);
            x /= 10;
        }

        if (sz(v) == sz(s))
            ans = i;
    }

    cout << ans << endl;
}
