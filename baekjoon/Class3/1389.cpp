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

    int n, m;
    int i, j;
    int kevin_count = 987654321, kevin_num, kevin[110];
    queue<pair<int, int>> q;
    bool visited[110] = {0, };
    vector<int> graph[101];
    cin >> n >> m;
    for (i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (i = 1; i <= n; i++)
    {
        int tmp = 0;
        visited[i] = true;
        for(j = 0; j< graph[i].size(); j++)
        {
            q.push(make_pair(graph[i][j], 1));
        }
        for (j = 1; j <= n; j++)
        {
            kevin[j] = 987654321;
            visited[j] = false;
        }
        while (!q.empty())
        {
            int cur = q.front().first;
            int cnt = q.front().second;
            q.pop();
            if (kevin[cur] > cnt) kevin[cur] = cnt;
            for (j = 0; j < graph[cur].size(); j++)
            {
                if (visited[graph[cur][j]] == false)
                {
                    q.push(make_pair(graph[cur][j], cnt + 1));
                    visited[graph[cur][j]] = true;
                }
            }
        }
        kevin[i] = 0;
        for (j = 1; j <= n; j++)
        {
            tmp += kevin[j];
        }
        if (kevin_count > tmp)
        {
            kevin_count = tmp;
            kevin_num = i;
        }
    }
    cout << kevin_num << "\n";
}