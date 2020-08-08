#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        string s;
        cin >> s;
        string ans;
        ans += s[0];
        for (int i = 1; i < s.size(); i += 2) {
            ans += s[i];
        }
        cout << ans << endl;
    }
}
