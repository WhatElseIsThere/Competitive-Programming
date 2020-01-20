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

    int n, s, k;
    cin >> n >> s >> k;

    set<int> closed;
    for (int i = 0; i < k; i++) {
        int floor;
        cin >> floor;
        closed.insert(floor);
    }

    int ans = INT_MAX;
    for (int i = max(s - k, 1); i <= min(s + k, n); i++) {
        if (closed.count(i) == 0)
            ans = min(ans, abs(s - i));
    }

    cout << ans << endl;
}
