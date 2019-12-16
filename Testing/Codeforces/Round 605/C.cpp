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
    string s;
    cin >> s;
    vector<char> c(k);
    for (int i = 0; i < k; i++)
        cin >> c[i];

    vector<int> pos;
    pos.push_back(-1);
    for (int i = 0; i < n; i++) {
        if (find(all(c), s[i]) == c.end())
            pos.push_back(i);
    }
    pos.push_back(n);

    ll ans = 0;
    for (int i = 1; i < sz(pos); i++) {
        int len = pos[i] - pos[i - 1] - 1;
        ans += len * 1LL * (len + 1) / 2;
    }

    cout << ans << endl;
}
