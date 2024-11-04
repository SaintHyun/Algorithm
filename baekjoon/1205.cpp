#include <bits/stdc++.h>
#include <stdio.h>
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

    int n, p, newScore, i;
    int scoreBoard[55] = {0};
    cin >> n >> newScore >> p;
    for (i = 1; i <= n; i++)
    {
        cin >> scoreBoard[i];
    }

    if (n == 0)
    {
        cout << "1\n";
        return 0;
    }

    if (n < p)
    {
        for (i = 1; i <= n + 1; i++)
        {
            if (scoreBoard[i] <= newScore)
            {
                cout << i << "\n";
                return 0;
            }
        }
    }
    else if (n == p)
    {
        for (i = 1; i < n; i++)
        {
            if (scoreBoard[i] <= newScore && newScore != scoreBoard[n])
            {
                cout << i << "\n";
                return 0;
            }
        }
        if(scoreBoard[i] < newScore)
        {
            cout << i << "\n";
            return 0;
        }
        cout << "-1\n";
    }
    return 0;
}