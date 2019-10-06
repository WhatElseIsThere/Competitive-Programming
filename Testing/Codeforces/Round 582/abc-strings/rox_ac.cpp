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
    string s, t;
    cin >> n >> s >> t;

    string ans;
    string p = "abc";
    do {
        string a;
        for (int i = 0; i < n; i++)
            a += p;
        if (a.find(s) == string::npos && a.find(t) == string::npos)
            ans = a;

        string b = string(n, p[0]) + string(n, p[1]) + string(n, p[2]);
        if (b.find(s) == string::npos && b.find(t) == string::npos)
            ans = b;
    } while (next_permutation(all(p)));

    cout << "YES" << endl;
    cout << ans << endl;
}
