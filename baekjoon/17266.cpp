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

    int n, m, light[100010];
    int i, left, mid, right, ans = 987654321;
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> light[i];
    }
    if(m == 1)
    {
        cout << n << "\n";
        return 0;
    }

    left = 0;
    right = n - 1;
    mid = n / 2;

    while (left <= right)
    {
        bool flag = true;
        mid = (left + right) / 2;
        if (light[0] - mid > 0 || light[m - 1] + mid < n)
        {
            left = mid + 1;
            flag = false;
            continue;
        }
        for (i = 0; i < m - 1; i++)
        {
            if (light[i] + mid < light[i + 1] - mid)
            {
                flag = false;
                left = mid + 1;
                break;
            }
        }
        if (flag == true)
        {
            ans = min(ans, mid);
            right = mid - 1;
        }   
    }
    cout << ans << "\n";

    return 0;
}