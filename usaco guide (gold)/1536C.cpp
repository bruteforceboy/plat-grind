#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int d = 0, k = 0;
    map<pair<int, int>, int> cnt;
    for (int i = 0; i < n; i++) {
      d += (s[i] == 'D');
      k += (s[i] == 'K');
      int g = gcd(d, k);
      int a = d / g;
      int b = k / g;
      if (cnt.count(make_pair(a, b))) {
        cout << cnt[make_pair(a, b)] + 1 << ' ';
      } else {
        cout << 1 << ' ';
      }
      cnt[make_pair(a, b)]++;
    }
    cout << '\n';   
  } 
  return 0;
}