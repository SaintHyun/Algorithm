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

    int n, m, k, i, j, space[55][55] = {0}, distance[55][55];
    int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1}, dy[8] = {0, 0, 1, -1, 1, -1, 1, -1}, maxx = -1;
    bool visited[55][55] = {0};
    int curX, curY, curcnt;
    int nextX, nextY;
    vector<pair<int, int>> shark;
    queue<pair<pair<int, int>, int>> q;
    cin >> n >> m;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            cin >> space[i][j];
            distance[i][j] = 987654321;
            if (space[i][j] == 1)
            {
                shark.push_back({i, j});
                q.push({{i, j}, 0});
            }
        }
    }

    for (k = 0; k < (int)shark.size(); k++)
    {
        q.push({{shark[k].first, shark[k].second}, 0});
        visited[shark[k].first][shark[k].second] = true;
        while (!q.empty())
        {
            curX = q.front().first.first;
            curY = q.front().first.second;
            curcnt = q.front().second;
            q.pop();

            if (curcnt < distance[curX][curY])
            {
                distance[curX][curY] = curcnt;
            }

            for (i = 0; i < 8; i++)
            {
                nextX = curX + dx[i];
                nextY = curY + dy[i];
                if (nextX >= 1 && nextX <= n && nextY >= 1 && nextY <= m && space[nextX][nextY] == 0 && visited[nextX][nextY] == false)
                {
                    visited[nextX][nextY] = true;
                    q.push({{nextX, nextY}, curcnt + 1});
                }
            }
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                visited[i][j] = false;
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (maxx < distance[i][j])
            {
                maxx = distance[i][j];
            }
        }
    }
    cout << maxx << "\n";

    return 0;
}