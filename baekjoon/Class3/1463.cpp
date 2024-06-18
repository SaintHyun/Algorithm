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

    int x, i, dp[1000001] = {0, };
    cin >> x;
    for (i = 2; i <= x; i++)
    {
        if (i % 3 == 0 && i % 2 != 0)
        {
            dp[i] = min(dp[i / 3] + 1, dp[i - 1] + 1);
        }
        else if (i % 2 == 0 && i % 3 != 0)
        {
            dp[i] = min(dp[i / 2] + 1, dp[i - 1] + 1);
        }
        else if (i % 2 == 0 && i % 3 == 0)
        {
            dp[i] = min(dp[i / 2] + 1, dp[i / 3] + 1);
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }
        else
            dp[i] = dp[i - 1] + 1;
    }
    cout << dp[x] << "\n";
}