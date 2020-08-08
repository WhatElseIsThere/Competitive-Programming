#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        auto calc = [&](char c) {
            int res = 0, bal = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] == c) {
                    ++bal;
                    continue;
                }
                if (bal == 0) {
                    ++res;
                } else {
                    --bal;
                }
            }
            return res;
        };

        int ans = calc('(');
        reverse(s.begin(), s.end());
        ans = min(ans, calc(')'));

        cout << ans << endl;
    }
}
