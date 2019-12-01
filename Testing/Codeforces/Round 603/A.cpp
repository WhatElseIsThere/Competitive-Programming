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
        vector<int> v(3);
        for (int i = 0; i < 3; i++)
            cin >> v[i];

        sort(all(v));
        int ans = (v[0] + v[1] + min(v[2], v[0] + v[1])) / 2;
        cout << ans << endl;
    }
}
