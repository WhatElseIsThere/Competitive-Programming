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

    int n, d, e;
    cin >> n >> d >> e;
    e *= 5;

    int ans = n;
    for (int i = 0; i <= n / d; i++)
        ans = min(ans, (n - i * d) % e);

    cout << ans << endl;
}
