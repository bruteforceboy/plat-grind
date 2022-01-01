#include <bits/stdc++.h>
using namespace std;

template <int mod> struct Modular {
  int value;
  Modular(int64_t v = 0) { value = v % mod; if (value < 0) value += mod; }

  Modular& operator+=(Modular const& b) { value += b.value; if (value >= mod) value -= mod; return *this; }
  Modular& operator-=(Modular const& b) { value -= b.value; if (value < 0) value += mod; return *this; }
  Modular& operator*=(Modular const& b) { value = (int64_t) value * b.value % mod; return *this; }
  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }

  friend Modular power(Modular a, int64_t e) {
    Modular res = 1; for (; e; e >>= 1, a *= a) if (e & 1) res *= a;
    return res;
  }
  friend Modular inverse(Modular a) { return power(a, mod - 2); }

  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }

  friend bool operator==(Modular const& a, Modular const& b) { return a.value == b.value; }
  friend bool operator!=(Modular const& a, Modular const& b) { return a.value != b.value; }

  friend ostream& operator<<(ostream& os, Modular const& a) { return os << a.value; }
};

using Mint = Modular <998244353>; // change this dummy! for dynamic mods attach to a constant

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<Mint>> dp(n + 2, vector<Mint>(2));
    for (int i = 0; i < n; i++) {
      dp[a[i] + 1][0] += dp[a[i] + 1][0]; // duplicating 
      dp[a[i] + 1][0] += dp[a[i]][0]; // adding

      if (a[i])
        dp[a[i] - 1][1] += dp[a[i] - 1][1]; 
      dp[a[i] + 1][1] += dp[a[i] + 1][1];
      if (a[i])
        dp[a[i] - 1][1] += dp[a[i] - 1][0];
      
      if (a[i] == 0) {
        dp[1][0] += 1;
      }
      if (a[i] == 1) {
        dp[0][1] += 1;
      }
    }
    Mint res = 0;
    for (int i = 0; i <= n + 1; i++) {
      res += dp[i][0];
      res += dp[i][1];
    }
    cout << res << '\n';
  }
  return 0;
}