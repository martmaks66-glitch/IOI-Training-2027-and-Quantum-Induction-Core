// High-Performance NTT for IOI 2027
#include <vector>
#include <iostream>

long long power(long long base, long long exp) {
    long long res = 1; base %= 998244353;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % 998244353;
        base = (base * base) % 998244353;
        exp /= 2;
    }
    return res;
}
void ntt(std::vector<long long>& a, bool invert) {
     int n = a.size();
     for (int i = 1, j = 0; i < n; i++)
{
          int bit = n >> 1;
          for (; j & bit; bit >>= 1) j ^= bit;
          j ^= bit;
          if (i < j) std::swap(a[i], a[j];
}
for (int len = 2; len <= n; len <<= 1) {
    long long wlen = power(3, (998244353 - 1) / len);
    if (invert) wlen = power(wlen, 998244353 - 2);
    for (int i = 0; i < n; i += len) {
         long long u = a[i+j], v = (a[i+j+len/2] * w) % 998244353;
         a[i+j] = (u + v) % 998244353;
         a[i+j+len/2] = (u - v + 998244353) % 998244353;
