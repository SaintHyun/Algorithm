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

    int n, i, stair[310] = {0};
    int dp[310] = {0};

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> stair[i];
    }
    dp[1] = stair[1];
    dp[2] = max(stair[2], stair[1] + stair[2]);
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    for (i = 4; i <= n; i++)
    {
        dp[i] = max(stair[i] + stair[i - 1] + dp[i - 3], stair[i] + dp[i - 2]);
    }
    cout << dp[n] << "\n";
}