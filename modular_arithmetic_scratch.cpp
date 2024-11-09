// author: arnavwinner

#include <bits/stdc++.h>
using namespace std;

struct ModInt {
  int value;
  static int mod;

  // Constructor
  ModInt(long long v = 0) {
    value = int(v % mod);
    if (value < 0) value += mod;
  }

  // Set modulus (use this once before any operations if a different mod is needed)
  static void set_mod(int m) {
    mod = m;
  }

  // Power function to handle division using modular inverse
  static int bin_power(int base, int exp) {
    int result = 1;
    while (exp > 0) {
      if (exp % 2 == 1) result = (1LL * result * base) % mod;
      base = (1LL * base * base) % mod;
      exp /= 2;
    }
    return result;
  }

  // Overloaded operators for modular arithmetic
  ModInt& operator+=(const ModInt& other) {
    value += other.value;
    if (value >= mod) value -= mod;
    return *this;
  }

  ModInt& operator-=(const ModInt& other) {
    value -= other.value;
    if (value < 0) value += mod;
    return *this;
  }

  ModInt& operator*=(const ModInt& other) {
    value = int((1LL * value * other.value) % mod);
    return *this;
  }

  ModInt& operator/=(const ModInt& other) {
    return *this *= ModInt(bin_power(other.value, mod - 2));
  }

  // Binary operators
  friend ModInt operator+(ModInt a, const ModInt& b) { return a += b; }
  friend ModInt operator-(ModInt a, const ModInt& b) { return a -= b; }
  friend ModInt operator*(ModInt a, const ModInt& b) { return a *= b; }
  friend ModInt operator/(ModInt a, const ModInt& b) { return a /= b; }

  // Stream output
  friend ostream& operator<<(ostream& out, const ModInt& m) {
    return out << m.value;
  }
};

// Define the static member outside the struct
int ModInt::mod = 1E9 + 7;  // Default mod value

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  // Set a custom modulus if needed
  // ModInt::set_mod(1E9 + 7);

  ModInt a = 10, b = 20;
  cout << "a + b = " << (a + b) << '\n';
  cout << "a - b = " << (a - b) << '\n';
  cout << "a * b = " << (a * b) << '\n';
  cout << "a / b = " << (a / b) << '\n';

  return 0;
}
