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

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<int> ab, ba;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a' && t[i] == 'b')
            ab.push_back(i);
        if (s[i] == 'b' && t[i] == 'a')
            ba.push_back(i);
    }

    if ((sz(ab) + sz(ba)) & 1) {
        cout << -1 << endl;
        return 0;
    }

    int ans = (sz(ab) + sz(ba)) / 2 + (sz(ab) & 1);

    cout << ans << endl;
    for (int i = 0; i + 1 < sz(ab); i += 2)
        cout << (ab[i] + 1) << ' ' << (ab[i + 1] + 1) << endl;
    for (int i = 0; i + 1 < sz(ba); i += 2)
        cout << (ba[i] + 1) << ' ' << (ba[i + 1] + 1) << endl;
    if (sz(ab) & 1) {
        cout << (ab.back() + 1) << ' ' << (ab.back() + 1) << endl;
        cout << (ab.back() + 1) << ' ' << (ba.back() + 1) << endl;
    }
}
