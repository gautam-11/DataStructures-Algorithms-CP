// Question Link: https://codeforces.com/contest/1194/problem/B

#include <bits/stdc++.h>
using namespace std;
int rows[50005];
int cols[50005];
int main()
{

    int q, n, m, i, j, x, y;
    cin >> q;

    while (q--)
    {
        cin >> n >> m;
        char matrix[n + 1][m + 1];

        memset(rows, 0, sizeof(rows));

        memset(cols, 0, sizeof(cols));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                cin >> matrix[i][j];
                if (matrix[i][j] == '*')
                {
                    rows[i] += 1;
                    cols[j] += 1;
                }
            }
        }
        int ans = INT_MAX;

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                int repeated = rows[i] + cols[j];
                if (matrix[i][j] == '*')
                {
                    repeated--;
                }
                ans = min(ans, n + m - 1 - repeated);
            }
        }
        cout << ans << endl;
    }
    return 0;
}