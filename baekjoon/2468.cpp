#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n, minn = 120, maxx = -1, ans = 1;
int town[110][110], rain[110][110];

void dfs(int s, int w)
{
    if(s<1 || s>n || w<1 || w>n) return;
    if(rain[s][w] <= 0) return;
    rain[s][w] = 0;

    dfs(s-1,w);
    dfs(s+1,w);
    dfs(s,w+1);
    dfs(s,w-1);
}

int solve(int k)
{
    int i, j, result = 0;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            rain[i][j] = town[i][j] - k;
        }
    }

    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(rain[i][j] >= 1)
            {
                result ++;
                dfs(i, j);
            }
        }
    }
    return result;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j;
    cin >> n;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            cin >> town[i][j];
            if(town[i][j] < minn) minn = town[i][j];
            if(town[i][j] > maxx) maxx = town[i][j];
        }
    }

    for(i=minn; i<maxx; i++)
    {
        ans = max(ans, solve(i));
    }
    cout << ans << "\n";
    return 0;
}