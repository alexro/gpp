#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(ll n, ll m)
{
    ll *r = new ll[n + 1];
    r[0] = 0;
    r[1] = 1;
    ll sm = 1;
    for (ll i = 2; i <= n; i++)
    {
        ll d = (m - (m / i) * r[m % i] % m) % m;
        r[i] = d;
        sm += d;
    }
    delete [] r;
    cout << sm << endl;
}

int main()
{
    ll n,m;
    cin >> n >> m;
    solve(n, m);
}

