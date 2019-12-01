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

        set<int> ans = {0};
        for (int i = 1; i * i <= n; i++) {
            ans.insert(i);
            ans.insert(n / i);
        }

        cout << sz(ans) << endl;
        for (auto x : ans)
            cout << x << ' ';
        cout << endl;
    }
}
