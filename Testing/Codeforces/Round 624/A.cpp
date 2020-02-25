#include <bits/stdc++.h>
using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int a, b;
        cin >> a >> b;
        int ans = 2;
        if (a == b) {
            ans = 0;
        } else if (a < b && (b - a) % 2 == 1) {
            ans = 1;
        } else if (b < a && (a - b) % 2 == 0) {
            ans = 1;
        }
        cout << ans << endl;
    }
}
