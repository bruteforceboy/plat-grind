#include <bits/stdc++.h>
using namespace std;

// don't use templates during practice
// make the solutions neater later 

const int N = 1e7;
int spf[N + 1];

void sieve() {
  for (int i = 1; i <= N; i++) {
    spf[i] = i;
  }

  for (int i = 2; i <= N; i += 2) {
    spf[i] = 2;
  }

  for (long long i = 3; i <= N; i += 2) {
    if (spf[i] == i) {
      for (long long j = i * i; j <= N; j += i) {
        spf[j] = i;
      }
    }
  }
}

vector<pair<int, int>> getFact(int n) {
  map<int, int> mp;
  while (n > 1) {
    int cur = spf[n];
    mp[cur]++;
    n /= cur;
  }
  return vector<pair<int, int>>(begin(mp), end(mp));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  sieve();
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  int ones = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ones += (a[i] == 1);
  }
  vector<pair<int, int>> val[n];
  map<vector<pair<int, int>>, int> cnt;
  for (int i = 0; i < n; i++) {
    auto fac = getFact(a[i]);
    vector<pair<int, int>> cur;
    for (auto& [x, y] : fac) {
      if (y % k > 0) {
        cur.emplace_back(x, y % k);
      }
    }
    val[i] = cur;
    cnt[cur]++;
  }
  long long res = 0;
  for (int i = 0; i < n; i++) {
    auto fac = getFact(a[i]);
    vector<pair<int, int>> cur;
    for (auto& [x, y] : fac) {
      int need = (k - (y % k)) % k;
      if (need > 0) {
        cur.emplace_back(x, need);
      }
    }
    if (cnt.count(cur)) {
      int ans = cnt[cur];
      if (val[i] == cur) {
        --ans;
      }
      res += ans;
    }
  }
  cout << (res >> 1) << '\n';
  return 0;
}