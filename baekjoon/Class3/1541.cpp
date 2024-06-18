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

    string equation, tmpnum;
    cin >> equation;
    int len = equation.length();
    int i, j, tmpsum = 0, ans = 0;
    bool minus_flag = false;

    for (i = 0; i <= len; i++)
    {
        if (equation[i] >= '0' && equation[i] <= '9')
        {
            tmpnum += equation[i];
        }
        else
        {
            if (minus_flag)
            {
                ans = ans - stoi(tmpnum);
                tmpnum.clear();
            }
            else
            {
                ans = ans + stoi(tmpnum);
                tmpnum.clear();
            }
        }
        if (equation[i] == '-')
        {
            minus_flag = true;
        }
    }
    cout << ans << "\n";
}