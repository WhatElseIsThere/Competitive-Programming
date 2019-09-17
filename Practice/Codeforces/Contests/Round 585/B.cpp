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

int sgn(int val) {
    return (val > 0 ? +1 : -1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    map<int, ll> ans;

    map<int, int> cnt;
    int cur = +1;
    cnt[cur]++;
    for (int i = 0; i < n; i++) {
        cur *= sgn(a[i]);
        ans[+1] += cnt[cur];
        ans[-1] += cnt[-cur];
        cnt[cur]++;
    }

    cout << ans[-1] << ' ' << ans[+1] << endl;
}
