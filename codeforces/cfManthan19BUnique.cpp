// Question Link :https://codeforces.com/contest/1208/problem/B
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{

    int n, i, j;
    int a[2005];
    unordered_map<ll, int> freq;
    freq.clear();

    cin >> n;

    int ans = INT_MAX;
    for (i = 0; i < n; i++)
        cin >> a[i];

    for (i = 0; i < n; i++)
    {

        bool distpre = true;

        for (j = 0; j < i; j++)
        {
            freq[a[j]]++;
            if (freq[a[j]] == 2)
            {
                distpre = false;
                break;
            }
        }
        int suffidx = n;
        for (j = n - 1; j >= i; j--)
        {
            freq[a[j]]++;
            if (freq[a[j]] == 1)
            {
                suffidx = j;
            }
            else
            {
                break;
            }
        }
        if (distpre)
            ans = min(ans, suffidx - i);

        freq.clear();
    }

    cout << ans << endl;
    return 0;
}