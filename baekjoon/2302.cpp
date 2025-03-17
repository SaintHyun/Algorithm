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

    int n, m, i, j, t;
    int ans = 1;
    int vip[44] = {0};
    int fib[44] = {1,1,2,0};
    for(i=3; i<=40; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    cin >> n >> m;
    for(i=1; i<=m; i++)
    {
        cin >> t;
        vip[i] = t;
    }

    for(j=1; j<=m; j++)
    {
        int tmp = vip[j] - vip[j-1] - 1;
        ans *= fib[tmp];
    }
    ans *= fib[n - vip[m]];
    cout << ans << "\n";

    return 0;
}