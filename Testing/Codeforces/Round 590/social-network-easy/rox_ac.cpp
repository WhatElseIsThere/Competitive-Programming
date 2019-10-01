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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> v;

    for (int i = 0; i < n; i++) {
        if (find(all(v), a[i]) != v.end())
            continue;
        if (sz(v) == k)
            v.pop_back();
        v.insert(v.begin(), a[i]);
    }

    cout << sz(v) << endl;
    for (auto x : v)
        cout << x << ' ';
    cout << endl;
}
