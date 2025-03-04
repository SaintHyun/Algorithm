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

    int n, l, i, j, k, ans = 0;
    int road[110][110];
    int row[110][110] = {0}, col[110][110] = {0};
    bool flag;
    cin >> n >> l;
    for (i = 0; i <= n + 1; i++)
    {
        for (j = 0; j <= n + 1; j++)
        {
            road[i][j] = -1;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> road[i][j];
        }
    }

    for (i = 1; i <= n; i++)
    {
        flag = true;
        for (j = 2; j <= n; j++)
        {
            if (road[i][j] == road[i][j - 1])
                continue;
            else if (road[i][j] == road[i][j - 1] - 1)
            {
                for (k = j; k < j + l; k++)
                {
                    if (road[i][k] != road[i][j] || row[i][k] != 0)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        row[i][k] = 1;
                    }
                }
            }
            else if (road[i][j] - 1 == road[i][j - 1])
            {
                for (k = j - l; k <= j - 1; k++)
                {
                    if (road[i][k] != road[i][j] - 1 || row[i][k] != 0)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        row[i][k] = 1;
                    }
                }
            }
            else
            {
                flag = false;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    for (j = 1; j <= n; j++)
    {
        flag = true;
        for (i = 2; i <= n; i++)
        {
            if (road[i][j] == road[i - 1][j])
                continue;
            else if (road[i][j] == road[i - 1][j] - 1)
            {
                for (k = i; k < i + l; k++)
                {
                    if (road[k][j] != road[i][j] || col[k][j] != 0)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        col[k][j] = 1;
                    }
                }
            }
            else if (road[i][j] - 1 == road[i - 1][j])
            {
                for (k = i - l; k <= i - 1; k++)
                {
                    if (road[k][j] != road[i][j] - 1 || col[k][j] != 0)
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        col[k][j] = 1;
                    }
                }
            }
            else
            {
                flag = false;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}