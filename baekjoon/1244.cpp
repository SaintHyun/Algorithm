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

    int n, i, m, j;
    int switches[110];

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> switches[i];
    }
    cin >> m;
    while (m--)
    {
        int gender, num;
        cin >> gender >> num;
        if (gender == 1)
        {
            for (i = num; i <= n; i += num)
            {
                switches[i] = 1 - switches[i];
            }
        }
        else
        {
            switches[num] = 1 - switches[num];
            for (i = num - 1, j = num + 1; i >= 1 && j <= n; i--, j++)
            {
                if (switches[i] == switches[j])
                {
                    switches[i] = 1 - switches[i];
                    switches[j] = 1 - switches[j];
                }
                else
                {
                    break;
                }
            }
        }
    }

    for (i = 1; i <= n; i++)
    {
        cout << switches[i] << " ";
        if (i % 20 == 0)
        {
            cout << "\n";
        }
    }
    cout << "\n";

    return 0;
}