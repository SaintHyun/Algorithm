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

    int n, m, x, y, k, i, j;
    int direct;
    int board[22][22], dx[5] = {0, 0, 0, -1, 1}, dy[5] = {0, 1, -1, 0, 0};
    int dice[6] = {0}, tmp1, tmp2, tmp3, tmp4;

    cin >> n >> m >> x >> y >> k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    int nextx, nexty;

    while (k--)
    {
        cin >> direct;
        nextx = x + dx[direct];
        nexty = y + dy[direct];

        // cout << nextx << " " << nexty << " " << direct <<"\n";

        if (nextx >= n || nextx < 0 || nexty >= m || nexty < 0)
        {
            continue;
        }

        x = nextx;
        y = nexty;

        switch (direct)
        {
        case 1:
            tmp1 = dice[1];
            tmp2 = dice[2];
            tmp3 = dice[3];
            tmp4 = dice[5];
            dice[1] = tmp2;
            dice[2] = tmp4;
            dice[3] = tmp1;
            dice[5] = tmp3;
            break;
        case 2:
            tmp1 = dice[1];
            tmp2 = dice[2];
            tmp3 = dice[3];
            tmp4 = dice[5];
            dice[1] = tmp3;
            dice[2] = tmp1;
            dice[3] = tmp4;
            dice[5] = tmp2;
            break;
        case 3:
            tmp1 = dice[0];
            tmp2 = dice[1];
            tmp3 = dice[4];
            tmp4 = dice[5];
            dice[0] = tmp2;
            dice[1] = tmp3;
            dice[4] = tmp4;
            dice[5] = tmp1;
            break;
        case 4:
            tmp1 = dice[0];
            tmp2 = dice[1];
            tmp3 = dice[4];
            tmp4 = dice[5];
            dice[0] = tmp4;
            dice[1] = tmp1;
            dice[4] = tmp2;
            dice[5] = tmp3;
            break;
        }

        if (board[x][y] == 0)
        {
            board[x][y] = dice[5];
            cout << dice[1] << "\n";
        }
        else if (board[x][y] != 0)
        {
            dice[5] = board[x][y];
            board[x][y] = 0;
            cout << dice[1] << "\n";
        }
    }

    return 0;
}