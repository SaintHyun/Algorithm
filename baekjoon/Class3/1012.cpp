#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int farm[51][51];
bool visited[51][51];
int n, m, k;

void count_island(int s, int w)
{
    if (s < 0 || w < 0 || s >= n || w >= m)
        return;
    if (farm[s][w] == 0 || visited[s][w] == true)
        return;
    visited[s][w] = true;
    count_island(s - 1, w);
    count_island(s + 1, w);
    count_island(s, w - 1);
    count_island(s, w + 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int i, j;
        int count = 0;
        cin >> n >> m >> k;
        for (i = 1; i <= k; i++)
        {
            int x, y;
            cin >> x >> y;
            farm[x][y] = 1;
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (farm[i][j] == 1 && visited[i][j] == false)
                {
                    count_island(i, j);
                    count += 1;
                }
            }
        }
        cout << count << "\n";
        for(i=0; i<51; i++)
        {
            for(j=0; j<51; j++)
            {
                farm[i][j] = 0;
                visited[i][j] = false;
            }
        }
    }
}