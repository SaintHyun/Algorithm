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

    int t;
    cin >> t;
    while (t--)
    {
        int n, x, y, i, destx, desty;
        bool flag = false;
        vector<pair<pair<int, int>, int>> conv;
        cin >> n >> x >> y;
        for (i = 0; i < n; i++)
        {
            int tmpa, tmpb;
            cin >> tmpa >> tmpb;
            conv.push_back({{tmpa, tmpb}, 0});
        }
        cin >> destx >> desty;

        queue<pair<pair<int, int>, int>> q;
        q.push({{x, y}, 20});
        while (!q.empty())
        {
            int curx = q.front().first.first;
            int cury = q.front().first.second;
            int curcnt = q.front().second;
            q.pop();

            if (abs(curx - destx) + abs(cury - desty) <= curcnt * 50)
            {
                cout << "happy\n";
                flag = true;
                break;
            }

            for (i = 0; i < n; i++)
            {
                if (conv[i].second == 0 && abs(curx - conv[i].first.first) + abs(cury - conv[i].first.second) <= curcnt * 50)
                {
                    q.push({{conv[i].first.first, conv[i].first.second}, 20});
                    conv[i].second = 1;
                }
            }
        }
        if (flag == false)
        {
            cout << "sad\n";
        }
    }

    return 0;
}