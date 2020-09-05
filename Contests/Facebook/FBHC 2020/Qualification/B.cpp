#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    for (int tc = 1; tc <= tcs; ++tc) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        int a = count(s.begin(), s.end(), 'A');
        int b = count(s.begin(), s.end(), 'B');
        char ans = (abs(a - b) == 1 ? 'Y' : 'N');

        cout << "Case #" << tc << ": " << ans << endl;
    }
}
