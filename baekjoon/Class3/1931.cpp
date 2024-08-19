#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second < b.second)
        return true;
    else if (a.second == b.second)
        return a.first < b.first;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, i, current_time, ans = 1;
    int tmpa, tmpb;
    vector<pair<int, int>> schedule;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> tmpa >> tmpb;
        schedule.push_back({tmpa, tmpb});
    }
    sort(schedule.begin(), schedule.end(), compare);

    current_time = schedule[0].second;
    for (i = 1; i < n; i++)
    {
        if (schedule[i].first >= current_time)
        {
            current_time = schedule[i].second;
            ans++;
        }
    }
    cout << ans << "\n";
}
