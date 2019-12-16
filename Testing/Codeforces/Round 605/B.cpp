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

    int q;
    cin >> q;

    while (q--) {
        string s;
        cin >> s;
        int h = min(count(all(s), 'L'), count(all(s), 'R'));
        int v = min(count(all(s), 'D'), count(all(s), 'U'));

        if (min(h, v) == 0) {
            if (max(h, v) == 0) {
                cout << 0 << endl;
                continue;
            } else {
                cout << 2 << endl;
                cout << (h ? "LR" : "DU") << endl;
            }
            continue;
        }

        cout << (2 * (h + v)) << endl;
        cout << string(h, 'L') << string(v, 'D') << string(h, 'R') << string(v, 'U') << endl;
    }
}
