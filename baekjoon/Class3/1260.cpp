#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, m, v;
vector<int> graph[1010];
bool visited_dfs[1010];
bool visited_bfs[1010];

void dfs(int v)
{
    visited_dfs[v] = true;
    cout << v << " ";
    for (int i = 0; i < graph[v].size(); i++)
    {
        if (visited_dfs[graph[v][i]] == false)
        {
            dfs(graph[v][i]);
        }
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (visited_bfs[cur] == false)
        {
            cout << cur << " ";
        }
        visited_bfs[cur] = true;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            if (visited_bfs[graph[cur][i]] == false)
            {
                q.push(graph[cur][i]);
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    cin >> n >> m >> v;
    for (i = 1; i <= m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    for (i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(v);
    cout << "\n";
    bfs(v);
    cout << "\n";
}