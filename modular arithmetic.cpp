#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int mod_add(int a, int b, int m = MOD);
int mod_sub(int a, int b, int m = MOD);
int mod_mul(int a, int b, int m = MOD);
int mod_pow(int base, int exp, int m = MOD);
int mod_inv(int a, int m = MOD /*shd be prime*/);
int mod_div(int a, int b, int m = MOD);

int main() { return 0; }

int mod_add(int a, int b, int m = MOD)
{
    a %= m;
    b %= m;
    int res = a + b;
    if (res >= m)
        res -= m;
    return res;
}

int mod_sub(int a, int b, int m = MOD)
{
    a %= m;
    b %= m;
    int res = a - b;
    if (res < 0)
        res += m;
    return res;
}

int mod_mul(int a, int b, int m = MOD) { return ((a % m) * (b % m)) % m; }

int mod_pow(int base, int exp, int m = MOD)
{
    int res = 1;
    base %= m;
    while (exp > 0)
    {
        if (exp & 1)
            res = (res * base) % m;
        base = (base * base) % m;
        exp >>= 1;
    }
    return res;
}

int mod_inv(int a, int m = MOD /*shd be prime*/)
{
    return mod_pow(a, m - 2, m);
}

int mod_div(int a, int b, int m = MOD) { return mod_mul(a, mod_inv(b, m), m); }