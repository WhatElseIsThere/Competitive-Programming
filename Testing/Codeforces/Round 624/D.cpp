#include <bits/stdc++.h>
using namespace std;

const int MAX_VAL = 2e4;

int main() {
    vector<vector<int>> divs(MAX_VAL + 1);
    for (int i = 1; i <= MAX_VAL; i++) {
        for (int j = i; j <= MAX_VAL; j += i) {
            divs[j].push_back(i);
        }
    }

    int tests;
    cin >> tests;
    while (tests--) {
        int a, b, c;
        cin >> a >> b >> c;
        int ans_val = 3 * MAX_VAL;
        int ans_A = -1, ans_B = -1, ans_C = -1;
        for (int B = 1; B <= MAX_VAL; ++B) {
            for (int A : divs[B]) {
                int k = c / B;
                int C_l = max(k, 1) * B, C_g = (k + 1) * B;
                int C = abs(C_l - c) < abs(C_g - c) ? C_l : C_g;
                int val = abs(A - a) + abs(B - b) + abs(C - c);
                if (val < ans_val) {
                    ans_val = val;
                    ans_A = A, ans_B = B, ans_C = C;
                }
            }
        }
        cout << ans_val << endl;
        cout << ans_A << ' ' << ans_B << ' ' << ans_C << endl;
    }
}
