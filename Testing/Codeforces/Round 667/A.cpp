#include <bits/stdc++.h>

using namespace std;

int main() {
    int tcs;
    cin >> tcs;

    while (tcs--) {
        int a, b;
        cin >> a >> b;
        cout << (abs(a - b) + 9) / 10 << endl;
    }
}
