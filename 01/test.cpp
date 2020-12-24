#pragma  GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int inv(long a, int mod) {
    int n = mod - 2;
    long res = 1;
    while (n) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

void solve1(int n, int m)
{
    long s = 1;
    for (int i = 2; i <= n; i++)
    {
        s += (long)inv(i, m);
    }
    cout << s << endl;
}

void solve2(long n, long m)
{
    long *r = new long[n + 1];
    r[0] = 0;
    r[1] = 1;
    long sm = 1;
    for (long i = 2; i <= n; i++)
    {
        long d = (m - (m / i) * r[m % i] % m) % m;
        r[i] = d;
        sm += d;
    }
    delete [] r;
    cout << sm << endl;
}

int main()
{
    long n,m;
    cin >> n >> m;
    solve2(n, m);
}

void main2()
{
    auto start = high_resolution_clock::now();
    solve2(100000000, 999999937);
    //solve2(1000, 9973);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << duration.count() << endl;
}

