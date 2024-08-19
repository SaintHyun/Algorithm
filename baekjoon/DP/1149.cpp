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

    int n, i, house[1010][4];
    int dp[1010][4];
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> house[i][1] >> house[i][2] >> house[i][3];
    }
    dp[1][1] = house[1][1];
    dp[1][2] = house[1][2];
    dp[1][3] = house[1][3];
    for (i = 2; i <= n; i++)
    {
        dp[i][1] = min(dp[i - 1][2] + house[i][1], dp[i - 1][3] + house[i][1]);
        dp[i][2] = min(dp[i - 1][1] + house[i][2], dp[i - 1][3] + house[i][2]);
        dp[i][3] = min(dp[i - 1][1] + house[i][3], dp[i - 1][2] + house[i][3]);
    }
    cout << min(min(dp[n][1], dp[n][2]), dp[n][3]) << "\n";
}