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

    int n, k, l, i;
    int board[110][110];
    int direct = 0, dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
    queue<pair<int, char>> q;
    queue<int> d;
    cin >> n >> k;

    int tmpa, tmpb;
    char tmpc;
    for (i = 0; i < k; i++)
    {
        cin >> tmpa >> tmpb;
        board[tmpa][tmpb] = 1;
    }
    cin >> l;
    for (i = 0; i < l; i++)
    {
        cin >> tmpa >> tmpc;
        q.push({tmpa, tmpc});
    }

    int cury = 1, curx = 1, curtime = 1;
    int taily = 1, tailx = 1;
    board[1][1] = 2;
    while (1)
    {
        cury += dy[direct];
        curx += dx[direct];
        d.push(direct);

        if (cury > n || cury < 1 || curx > n || curx < 1)
        {
            cout << curtime << "\n";
            return 0;
        }
        else if (board[cury][curx] == 2)
        {
            cout << curtime << "\n";
            return 0;
        }

        if (board[cury][curx] == 0)
        {
            board[taily][tailx] = 0;
            board[cury][curx] = 2;
            taily += dy[d.front()];
            tailx += dx[d.front()];
            d.pop();
        }
        else if (board[cury][curx] == 1)
        {
            board[cury][curx] = 2;
        }

        if (!q.empty() && curtime == q.front().first)
        {
            tmpa = q.front().first;
            tmpc = q.front().second;
            if (tmpc == 'D')
            {
                direct = (direct + 1) % 4;
            }
            if (tmpc == 'L')
            {
                direct = (direct + 3) % 4;
            }
            q.pop();
        }
        curtime++;
    }

    return 0;
}