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

const int SIGMA = 26;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = sz(s);

    vector<set<int>> pos(SIGMA);
    for (int i = 0; i < n; i++)
        pos[s[i] - 'a'].insert(i);

    int q;
    cin >> q;
    while (q--) {
        int qt;
        cin >> qt;
        if (qt == 1) {
            int i;
            char c;
            cin >> i >> c;
            i--;
            pos[s[i] - 'a'].erase(i);
            s[i] = c;
            pos[s[i] - 'a'].insert(i);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;

            int ans = 0;
            for (int i = 0; i < SIGMA; i++) {
                auto it = pos[i].lower_bound(l);
                if (it != pos[i].end() && *it <= r)
                    ans++;
            }

            cout << ans << endl;
        }
    }
}
