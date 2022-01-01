#include <bits/stdc++.h>
using namespace std;

const int N = 2e7;
int spf[N + 1];
int pf[N + 1];

void sieve() {
  for (int i = 0; i <= N; i++) {
    pf[i] = -1;
  }
  for (int i = 1; i <= N; i++) {
    spf[i] = i;
  }
  for (int i = 2; i <= N; i += 2) {
    spf[i] = 2;
  }
  for (int i = 3; i <= N; i += 2) {
    if (spf[i] == i) {
      for (long long j = 1ll * i * i; j <= N; j += i) {
        spf[j] = i;
      }
    }
  }
}

vector<int> get_divisors(const int& n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) {
        res.push_back(n / i);
      }
    }
  }
  return res;
}

int get_prime_factors_count(int n) {
  if (pf[n] != -1) return pf[n];
  int tmp = n, res = 0;
  while (n > 1) {
    ++res;
    int x = spf[n];
    while (n % x == 0) {
      n /= x;
    }
  }
  return pf[tmp] = res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // count the number of of pair(a, b)
  // with lcm L and gcd G
  // given that the lcm and gcd of the two numbers(a, b) 
  // let L = gcd, G = gcd 
  // L = (a * b) / G 
  // L * G = a * b 
  // a can be represented as some A * G
  // b can be represented as some B * G 
  // L * G = A * G * B * G 
  // divide both sides by G^2 
  // L / G = A * B 
  // gcd(A, B) = 1, since we've removed the gcd 
  // since A and B don't have a common divisor 
  // any prime factor appearing in A shouldn't appear in B and vice-versa 
  // so the number of pairs (A, B) will be the 2^(total number of prime factors of L / G)
  // back to the original problem
  // finding the gcd and lcm is trivial   
 
  sieve();

  int t;
  cin >> t;
  while (t--) {
    int c, d, x;
    cin >> c >> d >> x;

    vector<int> divs = get_divisors(x);

    long long res = 0;
    for (const int& g : divs) {
      long long val = x / g + d;
      if (val % c) continue;
      val /= c;

      int pf = get_prime_factors_count(val);
      res += (1ll << pf);
    }

    cout << res << '\n';
  }
  return 0;
}