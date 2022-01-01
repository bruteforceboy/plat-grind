#include <bits/stdc++.h>
using namespace std;

// prime factorization....

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long n;
  cin >> n;
  auto f = [&](int x) {
    int lo = 0, hi = 100, ans = 0;
    while (lo <= hi) {
      int mid = lo + hi >> 1;
      if ((mid * (mid + 1)) >> 1 <= x) {
        ans = mid;
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
    return ans;
  };
  int res = 0;
  for (long long i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      int cnt = 0;
      while (n % i == 0)
        ++cnt, n /= i;
      res += f(cnt);
    }
  }
  res += (n >= 2);
  cout << res << '\n';
  return 0;
}