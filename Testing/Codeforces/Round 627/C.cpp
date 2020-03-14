#include <bits/stdc++.h>

using namespace std;

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    string s;
    cin >> s;
    s += 'R';
    int ans = INT_MIN, prv = -1;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'R') {
        ans = max(ans, i - prv);
        prv = i;
      }
    }
    cout << ans << endl;
  }
}
