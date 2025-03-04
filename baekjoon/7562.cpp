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

    int t, i;
    int l, x, y, destx, desty;
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    cin >> t;
    while (t--)
    {
        cin >> l;
        cin >> x >> y >> destx >> desty;
        queue<pair<pair<int, int>, int>> q;
        bool visited[330][330] = {0};
        int curx, cury, curcnt;
        q.push({{x, y}, 0});
        visited[x][y] = true;
        while (!q.empty())
        {
            curx = q.front().first.first;
            cury = q.front().first.second;
            curcnt = q.front().second;

            q.pop();
            if (curx == destx && cury == desty)
            {
                cout << curcnt << "\n";

                break;
            }
            for (i = 0; i < 8; i++)
            {
                int nextx = curx + dx[i];
                int nexty = cury + dy[i];
                if (nextx >= 0 && nextx < l && nexty >= 0 && nexty < l && visited[nextx][nexty] == false)
                {
                    q.push({{nextx, nexty}, curcnt + 1});
                    visited[nextx][nexty] = true;
                }
            }
        }
    }

    return 0;
}