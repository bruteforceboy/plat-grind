#include <bits/stdc++.h>
using namespace std;

// observation?? 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> res;
  long long product = 1;
  for (int i = 1; i <= n - 1; i++) {
    if (gcd(i, n) == 1) {
      res.push_back(i);
      product = (product * i) % n;
    }
  }
  if (product != 1) {
    res.pop_back();
  }
  cout << (int) res.size() << '\n';
  for (int p : res) {
    cout << p << ' ';
  }
  cout << '\n';
  return 0;
}