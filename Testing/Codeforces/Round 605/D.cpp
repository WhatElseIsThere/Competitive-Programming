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

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> l(n), r(n);

    l[0] = 1;
    for (int i = 1; i < n; i++)
        l[i] = (a[i] > a[i - 1] ? l[i - 1] + 1 : 1);

    r[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
        r[i] = (a[i] < a[i + 1] ? r[i + 1] + 1 : 1);

    int ans = *max_element(all(l));
    for (int i = 1; i + 1 < n; i++) {
        if (a[i - 1] < a[i + 1])
            ans = max(ans, l[i - 1] + r[i + 1]);
    }

    cout << ans << endl;
}
