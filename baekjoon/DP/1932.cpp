#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tri[501][501] = {0}, i, j, dp[501][501] = {0}, ans = -1;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            cin >> tri[i][j];
        }
    }
    dp[1][1] = tri[1][1];
    for (i = 2; i <= n; i++)
    {
        for (j = 1; j <= i; j++)
        {
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + tri[i][j];
        }
    }
    for (i = 1; i <= n; i++)
    {
        ans = max(ans, dp[n][i]);
    }
    cout << ans << "\n";
}