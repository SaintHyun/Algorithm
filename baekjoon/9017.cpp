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
    int minn = 987654321, ans;
    int score[210][10] = {0};
    int tmp, tmpa, tmpb;
    vector<int> q;
    while (t--)
    {
        minn = 987654321;
        int i, j, n, m;
        cin >> n;
        m = -1;
        for(i=0; i<=209; i++)
        {
            for(j=0; j<=9; j++)
            {
                score[i][j] = 0;
            }
        }
        q.push_back(0);
        for (i = 1; i <= n; i++)
        {
            cin >> tmp;
            q.push_back(tmp);
            score[tmp][0] += 1;
            m = max(m, tmp);
        }
        for (i = 1; i <= m; i++)
        {
            if (score[i][0] < 6)
            {
                for (j = 1; j <= n; j++)
                {
                    if (q[j] == i)
                    {
                        q.erase(q.begin() + j);
                        n--;
                        j--;
                    }
                }
            }
        }

        for (i = 1; i <= n; i++)
        {
            if (score[q[i]][0] == 6 && score[q[i]][8] < 4)
            {
                score[q[i]][7] += i;
                score[q[i]][8] += 1;
                if (score[q[i]][8] == 4)
                {
                    score[q[i]][9] = i;
                }
            }
        }
        for (i = 1; i <= m; i++)
        {
            // cout << score[i][7] << "\n";
            if (score[i][7] != 0 && minn > score[i][7])
            {
                minn = score[i][7];
                ans = i;
            }
            else if (minn == score[i][7])
            {
                for (j = score[ans][9] + 1; j <= n; j++)
                {
                    if (q[j] == ans)
                    {
                        tmpa = j;
                        break;
                    }
                }
                for (j = score[i][9] + 1; j <= n; j++)
                {
                    if (q[j] == i)
                    {
                        tmpb = j;
                        break;
                    }
                }
                if (tmpb < tmpa)
                {
                    ans = i;
                }
            }
        }
        // for(i=1; i<=n; i++)
        // {
        //     cout << q[i] << " ";
        // }
        // cout <<"\n";
        // for(i=1; i<=m; i++)
        // {
        //     cout << score[i][7] << " ";
        // }
        // cout <<"\n";

        cout << ans << "\n";
        q.clear();
    }

    return 0;
}