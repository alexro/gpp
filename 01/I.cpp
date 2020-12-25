#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(long n, long m)
{
    long *r = new long[n + 1];
    r[0] = 0;
    r[1] = 1;
    ll sm = 1;
    for (long i = 2; i <= n; i++)
    {
        long o1 = m / i;
        long o2 = r[m % i];
        ll o3 = (ll)o1 * (ll)o2;
        long o4 = (long)(o3 % m);
        long d = (m - o4) % m;
        r[i] = d;
        sm += d;
    }
    delete [] r;
    cout << sm << endl;
}

int main()
{
    long n, m;
    cin >> n >> m;
    solve(n, m);
}

