#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll inv(ll a, long mod) {
    long m = mod - 2;
    ll b = 1;
    while (m) {
        if (m & 1) b = b * a % mod;
        a = a * a % mod;
        m >>= 1;
    }
    return b;
}

void solve1(long n, long m)
{
    ll s = 1;
    for (long i = 2; i <= n; i++)
    {
        s += inv(i, m);
    }
    cout << s << endl;
}

void solve(ll n, ll m)
{
    long c = 60000000;
    ll *r = new ll[c + 1];
    r[0] = 0;
    r[1] = 1;
    ll sm = 1;
    for (ll i = 2; i <= n; i++)
    {
        long c2 = m % i;
        long c3 = c2 <= c ? r[c2] : inv(c2, m);
        ll d = (m - (m / i) * c3 % m) % m;
        if (i <= c)
            r[i] = d;
        sm += d;
    }
    delete [] r;
    cout << sm << endl;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    solve(n, m);
}

