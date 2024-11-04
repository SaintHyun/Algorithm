#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, x, y, m;
vector<int> family[110];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    cin >> n >> x >> y >> m;
    for (i = 1; i <= m; i++)
    {
        int tmpa, tmpb;
        cin >> tmpa >> tmpb;
        family[tmpa].push_back(tmpb);
        family[tmpb].push_back(tmpa);
    }

    queue<pair<int, int>> q;
    bool visited[110] = {0};
    q.push({x, 0});
    while (!q.empty())
    {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();
        visited[cur] = true;

        if (cur == y)
        {
            cout << cnt << "\n";
            return 0;
        }

        for (i = 0; i < (int)family[cur].size(); i++)
        {
            int next = family[cur][i];
            if (visited[next] == false)
            {
                q.push({next, cnt + 1});
            }
        }
    }
    cout << "-1\n";

    return 0;
}