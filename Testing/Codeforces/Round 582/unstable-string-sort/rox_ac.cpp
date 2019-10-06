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

    int n, k;
    cin >> n >> k;
    vector<int> p1(n), p2(n);
    for (int i = 0; i < n; i++) {
        cin >> p1[i];
        p1[i]--;
    }
    for (int i = 0; i < n; i++) {
        cin >> p2[i];
        p2[i]--;
    }

    vector<int> p1Rev(n), p2Rev(n);
    for (int i = 0; i < n; i++) {
        p1Rev[p1[i]] = i;
        p2Rev[p2[i]] = i;
    }

    string ans(n, ' ');
    int cur = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        int j = p2Rev[p1[i]];
        if (j > 0)
            mx = max(mx, p1Rev[p2[j - 1]]);
        ans[p1[i]] = char('a' + cur);
        if (mx <= i)
            cur = min(cur + 1, 25);
    }

    int last = (*max_element(all(ans)) - 'a');
    if (last + 1 < k) {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    cout << ans << endl;
}
