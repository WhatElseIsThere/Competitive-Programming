#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> p(m);
        for (int i = 0; i < m; ++i) {
            cin >> p[i];
            --p[i];
        }

        vector<bool> in_p(n);
        for (int x : p) {
            in_p[x] = true;
        }
        
        for (int i = 0; i < n; ) {
            if (!in_p[i]) {
                ++i;
                continue;
            }

            int l = i;
            while (i < n && in_p[i]) {
                ++i;
            }
            int r = i + 1;

            sort(a.begin() + l, a.begin() + r);
        }

        bool ans = true;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] > a[i + 1]) {
                ans = false;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }
}

