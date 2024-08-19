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

    int n, m, i, j;
    int maze[110][110];
    bool visited[110][110] = {false};
    int cury, curx, curcnt;
    int dy[4] = {1, -1, 0, 0}, dx[4] = {0, 0, 1, -1};
    string tmp;
    queue<pair<pair<int, int>, int>> q;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        cin >> tmp;
        for (j = 1; j <= m; j++)
        {
            maze[i][j] = tmp[j - 1] - '0';
        }
    }
    q.push({{1, 1}, 1});
    visited[1][1] = true;
    while (!q.empty())
    {
        cury = q.front().first.first;
        curx = q.front().first.second;
        curcnt = q.front().second;
        q.pop();
        if (cury == n && curx == m)
        {
            cout << curcnt << "\n";
            return 0;
        }
        for (i = 0; i < 4; i++)
        {
            int nexty = cury + dy[i];
            int nextx = curx + dx[i];
            if ((nexty >= 1 && nexty <= n && nextx >= 1 && nextx <= m) && maze[nexty][nextx] == 1 && visited[nexty][nextx] == false)
            {
                visited[nexty][nextx] = true;
                q.push({{nexty, nextx}, curcnt + 1});
            }
        }
    }
}