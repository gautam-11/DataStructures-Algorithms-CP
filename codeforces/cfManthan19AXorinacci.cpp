// Question Link : https://codeforces.com/contest/1208/problem/A

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    ll a, b, n;

    cin >> t;

    while (t--)
    {
        cin >> a >> b >> n;
        ll c = a ^ b;
        ll x = n % 3;
        ll ans = x == 0 ? a : x == 1 ? b : c;
        cout << ans << endl;
    }

    return 0;
}