// Question Link : https://codeforces.com/contest/1186/problem/C

#include <bits/stdc++.h>
using namespace std;
int sumOnes[1000006];

int main()
{

    ios_base::sync_with_stdio(0);

    string str, substr;

    cin >> str >> substr;

    int substrLen, oneCount, i;

    substrLen = substr.length();

    for (i = 0; i < substrLen; i++)
    {
        oneCount += substr[i] == '1' ? 1 : 0;
    }
    int len = str.length();

    memset(sumOnes, 0, sizeof(sumOnes));

    sumOnes[0] = 0;

    for (i = 1; i <= len; i++)
    {

        sumOnes[i] = str[i - 1] == '1' ? 1 + sumOnes[i - 1] : sumOnes[i - 1];
    }
    int ans = 0;

    for (i = substrLen; i <= len; i++)
    {

        ans += (sumOnes[i] - sumOnes[i - substrLen] + oneCount) % 2 == 0 ? 1 : 0;
    }

    cout << ans << endl;

    return 0;
}