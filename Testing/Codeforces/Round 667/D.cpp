#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dig_sum(ll n) {
    int res = 0;
    while (n) {
        res += (n % 10);
        n /= 10;
    }
    return res;
}

void update(ll& n) {
    ll pw = 1;
    while (n % 10 == 0) {
        n /= 10;
        pw *= 10;
    }
    n = (n + 10 - (n % 10)) * pw;
}

int main() {
    int tcs;
    cin >> tcs;

    while (tcs--) {
        ll n;
        int s;
        cin >> n >> s;
        ll _n = n;
        while (dig_sum(n) > s) update(n);
        cout << (n - _n) << endl;
    }
}
