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

    int p, t, i, j, ans;
    int height[21];
    cin >> p;
    
    while(p--)
    {
        cin >> t;
        ans = 0;
        for(i=1; i<=20; i++)
        {
            cin >> height[i];
        }

        for(i=1; i<=19; i++)
        {
            for(j=i+1; j<=20; j++)
            {
                if(height[i] > height[j]) ans++;
            }
        }
        cout << t << " " << ans << "\n";
    }
    return 0;
}