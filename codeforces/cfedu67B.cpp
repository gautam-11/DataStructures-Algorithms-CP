//Question Link:https://codeforces.com/contest/1187/problem/B

#include <bits/stdc++.h>
using namespace std;

vector<int> pos[26];
int main()
{

    int n, m, i, j;
    string s, t;
    char x;
    ios_base::sync_with_stdio(0);
    cin >> n;
    cin >> s;
    for (i = 0; i < s.size(); i++)
    {
        pos[s[i] - 'a'].push_back(i + 1);
    }
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> t;
        vector<int> cnt(26);
        for (j = 0; j < t.size(); j++)
            cnt[t[j] - 'a']++;

        int ans = -10000;

        for (j = 0; j < 26; j++)
            if (cnt[j] > 0)
                ans = max(ans, pos[j][cnt[j] - 1]);

        cout << ans << endl;
    }
    return 0;
}