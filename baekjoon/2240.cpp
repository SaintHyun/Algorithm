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

    int zadu[1010], dp[1010][31] = {0};
    int t, w, i, j, ans = -1;
    cin >> t >> w;
    for (i = 1; i <= t; i++)
    {
        cin >> zadu[i];
    }
    if (zadu[1] == 1)
    {
        dp[1][0] = 1;
        dp[1][1] = 0;
    }
    else if (zadu[1] == 2)
    {
        dp[1][0] = 0;
        dp[1][1] = 1;
    }
    for (i = 2; i <= t; i++)
    {
        for (j = 0; j <= min(w, i - 1); j++)
        {
            if (j % 2 == 0)
            {
                if (zadu[i] == 1)
                {
                    if (j + 1 <= min(w, i - 1))
                        dp[i][j + 1] = max(dp[i - 1][j], dp[i][j]);
                    dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j]);
                }
                else if (zadu[i] == 2)
                {
                    if (j + 1 <= min(w, i - 1))
                        dp[i][j + 1] = max(dp[i - 1][j] + 1, dp[i][j]);
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                }
            }
            else if (j % 2 == 1)
            {
                if (zadu[i] == 2)
                {
                    if (j + 1 <= min(w, i - 1))
                        dp[i][j + 1] = max(dp[i - 1][j], dp[i][j]);
                    dp[i][j] = max(dp[i - 1][j] + 1, dp[i][j]);
                }
                else if (zadu[i] == 1)
                {
                    if (j + 1 <= min(w, i - 1))
                        dp[i][j + 1] = max(dp[i - 1][j] + 1, dp[i][j]);
                    dp[i][j] = max(dp[i - 1][j], dp[i][j]);
                }
            }
        }
    }

    for (i = 0; i <= w; i++)
    {
        ans = max(dp[t][i], ans);
    }
    cout << ans << "\n";
    return 0;
}