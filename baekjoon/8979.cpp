#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool compare(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    if (a.first.second > b.first.second)
        return true;
    else if (a.first.second == b.first.second && a.second.first > b.second.first)
        return true;
    else if (a.first.second == b.first.second && a.second.first == b.second.first && a.second.second > b.second.second)
        return true;
    else
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

    vector<pair<pair<int, int>, pair<int, int>>> medals;
    int tmpa, tmpb, tmpc, tmpd;
    int cur_rank = 1, dup = 0;
    int n, k, i;
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        cin >> tmpa >> tmpb >> tmpc >> tmpd;
        medals.push_back({{tmpa, tmpb}, {tmpc, tmpd}});
    }
    sort(medals.begin(), medals.end(), compare);
    if (medals[0].first.first == k)
    {
        cout << "1\n";
        return 0;
    }

    for (i = 1; i < n; i++)
    {
        if (medals[i - 1].first.second == medals[i].first.second && medals[i - 1].second.first == medals[i].second.first && medals[i - 1].second.second == medals[i].second.second)
        {
            dup++;
        }
        else
        {
            cur_rank += dup + 1;
            dup = 0;
        }
        if (medals[i].first.first == k)
        {
            cout << cur_rank << "\n";
            return 0;
        }
    }
}