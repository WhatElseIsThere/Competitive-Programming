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

    int a1, a2, k1, k2, n;
    cin >> a1 >> a2 >> k1 >> k2 >> n;

    if (k1 > k2) {
        swap(a1, a2);
        swap(k1, k2);
    }

    int ansMax = ((n <= a1 * k1) ? (n / k1) : (a1 + (n - a1 * k1) / k2));
    int ansMin = max(n - (a1 * (k1 - 1) + a2 * (k2 - 1)), 0);

    cout << ansMin << ' ' << ansMax << endl;
}
