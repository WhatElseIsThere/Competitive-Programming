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
        string s;
        cin >> s;

        int ans = 0, lastA = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'P' && lastA != -1)
                ans = max(ans, i - lastA);
            if (s[i] == 'A')
                lastA = i;
        }

        cout << ans << endl;
    }
}
