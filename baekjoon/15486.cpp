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

    vector<pair<int, int>> schedule;
    int dp[1500061] = {0};

    int i, tmpa, tmpb, n;
    cin >> n;
    schedule.push_back({0, 0});
    for (i = 1; i <= n; i++)
    {
        cin >> tmpa >> tmpb;
        schedule.push_back({tmpa, tmpb});
    }

    for (i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i], dp[i - 1]);
        dp[i + schedule[i].first - 1] = max(dp[i - 1] + schedule[i].second, dp[i + schedule[i].first - 1]);
    }
    cout << dp[n] << "\n";

    return 0;
}