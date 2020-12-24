#include <bits/stdc++.h>
using namespace std;

void solve(long n, long m)
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
    solve(n, m);
}

