#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();

        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string s = a.substr(i, j - i + 1);
                if (b.find(s) != string::npos) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        cout << (n + m - 2 * max_len) << endl;
    }
}
