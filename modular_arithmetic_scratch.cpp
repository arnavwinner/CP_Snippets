
// author: arnavwinner

#include <bits/stdc++.h>
using namespace std;
// assuming mod is defined at the top
const int mod = 1E9 + 7;

int bin_power(int b, int e) {
  if (e == 0) return 1;
  long long b_ = b;
  long long ans = 1;
  while (e > 1) {
    if (e % 2 == 0) {
      e /= 2;
      b_ *= b_;
      b_ %= mod;
    } else {
      e--;
      ans *= b_;
      ans %= mod;
    }
  }
  b_ *= ans;
  b_ %= mod;
  b = b_;
  return b;
}

void mod_add(int &a, int b) {
  long long a_ = a;
  a_ += b;
  a_ %= mod;
  a = a_;
}

void mul_mod(int &a, int b) {
  long long a_ = a;
  a_ *= b;
  a_ %= mod;
  a = a_;
}

void sub_mod(int &a, int b) {
  long long a_ = a;
  long long b_ = b;
  a_ -= b_;
  a_ %= mod;
  a_ += mod;
  a_ %= mod;
  a = a_;
}

void div_mod(int &a, int b) {
  // a * b^-1
  int inv_b = bin_power(b, mod - 2);
  mul_mod(a, inv_b);
} // check all working?

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << bin_power(2, 2) << '\n';
  return 0;
}