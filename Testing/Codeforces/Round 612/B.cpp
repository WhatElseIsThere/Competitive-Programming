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
    vector<string> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    map<string, bool> have;
    for (auto t : s)
        have[t] = true;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            string toFind;
            for (int p = 0; p < k; p++) {
                if (s[i][p] == s[j][p])
                    toFind.push_back(s[i][p]);
                else
                    toFind.push_back('S' + 'E' + 'T' - s[i][p] - s[j][p]);
            }
            if (have.find(toFind) != have.end())
                ans++;
        }
    }

    cout << (ans / 3) << endl;
}
