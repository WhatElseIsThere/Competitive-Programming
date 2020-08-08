#include <bits/stdc++.h>

using namespace std;

int sq(int x) {
  return x * x;
}

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    cout << sq(max(2 * a, b)) << endl;
  }
}
