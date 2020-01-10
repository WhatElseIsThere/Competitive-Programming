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

    int tests;
    cin >> tests;

    while (tests--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        ll maxSum = 0;
        ll cur = 0, curMin = 0;
        for (int i = 0; i < n - 1; i++) {
            cur += a[i];
            maxSum = max(maxSum, cur - curMin);
            curMin = min(curMin, cur);
        }

        cur = 0;
        for (int i = n - 1; i > 0; i--) {
            cur += a[i];
            maxSum = max(maxSum, cur);
        }
        cur += a[0];

        cout << (cur > maxSum ? "YES" : "NO") << endl;
    }
}
