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
    int i, j, k;
    int broken[10] = {0, }, cur = 100;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> k;
        broken[k] = 1;
    }
    int ans = abs(n - cur);
    if (broken[0] == 0)
    {
        if (ans > abs(n) + 1)
            ans = abs(n) + 1;
    }
    for (i = 1; i <= 1000000; i++)
    {
        cur = i;
        k = 0;
        while (cur > 0)
        {
            if (broken[cur % 10] == 1)
            {
                k = 0;
                break;
            }
            k++;
            cur /= 10;
        }
        if (k && ans > abs(n - i) + k)
            ans = abs(n - i) + k;
    }
    cout << ans << "\n";
}