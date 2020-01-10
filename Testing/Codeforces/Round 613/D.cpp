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

const int BITS = 30;

int solve(vector<int> a, int pos) {
    if (pos == -1)
        return 0;

    vector<int> a0, a1;
    for (auto x : a) {
        if ((x >> pos) & 1)
            a1.push_back(x);
        else
            a0.push_back(x);
    }

    if (a0.empty())
        return solve(a1, pos - 1);

    if (a1.empty())
        return solve(a0, pos - 1);

    return (1 << pos) + min(solve(a0, pos - 1), solve(a1, pos - 1));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << solve(a, BITS - 1) << endl;
}
