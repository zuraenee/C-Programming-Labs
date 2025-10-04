#include <iostream>
#include <vector>
#include <bits/stdc++.h>

#include <bits/stdc++.h>
using namespace std;

// fractional part in [0,1)
static inline double fpart(double x) {
    x = x - floor(x);
    return x < 0 ? x + 1.0 : x;
}

// (base^exp) mod mod using fast exponentiation
static long long powmod(long long base, long long exp, long long mod) {
    long long res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

// S(j, n) term from the BBP digit-extraction method
// S(j, n) = sum_{k=0..n} (16^{n-k} mod (8k+j)) / (8k+j)   [taken frac part]
//         + sum_{k=n+1..∞} 16^{n-k} / (8k+j)              [as doubles]
static double S(int j, int n) {
    double s = 0.0;
    for (int k = 0; k <= n; ++k) {
        long long ak = 8LL * k + j;
        long long p  = powmod(16, n - k, ak);
        s += static_cast<double>(p) / static_cast<double>(ak);
        s = fmod(s, 1.0); // keep only fractional part to control growth
    }

    // rapidly converging tail
    double t = 0.0;
    int k = n + 1;
    double pow16 = 1.0 / 16.0; // 16^{n-(n+1)} = 16^{-1}
    while (true) {
        double term = pow16 / (8.0 * k + j);
        if (term < 1e-17) break; // good enough for one hex digit
        t += term;
        pow16 /= 16.0;
        ++k;
    }

    return fpart(s + t);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    // fractional part of 16^n * pi via BBP
    double x = 4.0 * S(1, n) - 2.0 * S(4, n) - S(5, n) - S(6, n);
    x = fpart(x); // ensure in [0,1)

    // nth hex digit is floor(16 * frac)
    int digit = static_cast<int>(floor(16.0 * x));
    if (digit < 0) digit = 0;      // safety clamps
    if (digit > 15) digit = 15;

    char hexch = (digit < 10) ? ('0' + digit) : ('a' + (digit - 10));
    cout << hexch << "\n";
    return 0;
}


// (Note: treat this as an optional question - only for those who find the above questions "too simple". It requires a bit of math knowledge explained - but not quite fully - in the second link below.)

// [20 points] You know the number pi:

// pi = 3.141592653589...
// When expressed in hexadecimal (base 16), it looks like this:
// pi = 3.243f6a8885a3...
// It turns out there is a way to calculate directly any digit of pi, without first calculating all the digits before it. Unfortunately it only works in base 16, not base 10. Here is the algorithm. Implement it into a C++ program. It should read an integer n, and print the n-th digit of pi. Use the symbols 0-9 and a-f. (Following the notation in the above link, the first digit after the dot is the "0-th" digit.)
