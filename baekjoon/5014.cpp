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

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;
    int visited[1000010] = {0};
    queue<int> q;
    q.push(s);
    int cur;
    visited[s] = 1;

    while (!q.empty())
    {
        cur = q.front();
        q.pop();

        if (cur == g)
        {
            cout << visited[cur] - 1 << "\n";
            return 0;
        }

        if (cur + u <= f && visited[cur + u] == 0)
        {
            q.push(cur + u);
            visited[cur + u] = visited[cur] + 1;
        }
        if (cur - d >= 1 && visited[cur - d] == 0)
        {
            q.push(cur - d);
            visited[cur - d] = visited[cur] + 1;
        }
    }

    cout << "use the stairs\n";

    return 0;
}