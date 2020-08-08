#include <bits/stdc++.h>

using namespace std;

int main() {
    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        int k2 = 0, k3 = 0;
        while (n % 2 == 0) {
            ++k2;
            n /= 2;
        }
        while (n % 3 == 0) {
            ++k3;
            n /= 3;
        }
        if (n != 1 || k2 > k3) {
            cout << -1 << endl;
           continue;
        }
        cout << (2 * k3 - k2) << endl;
    }
}
