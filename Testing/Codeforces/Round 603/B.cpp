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

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (count(all(v), v[i]) > 1) {
                ans++;
                for (int j = 0; j < 10; j++) {
                    v[i][3] = char('0' + j);
                    if (count(all(v), v[i]) == 1)
                        break;
                }
            }
        }

        cout << ans << endl;
        for (auto s : v)
            cout << s << endl;
    }
}
