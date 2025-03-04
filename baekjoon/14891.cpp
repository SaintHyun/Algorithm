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

    string w[5];
    int i, j, n;
    bitset<8> wheel[5];
    bitset<8> tmp[5];

    for (i = 1; i <= 4; i++)
    {
        cin >> w[i];
        for (j = 0; j < 8; j++)
        {
            wheel[i][j] = w[i][j] - '0';
        }
        // cout << wheel[i] << "\n";
    }
    cin >> n;
    int num, direct;
    while (n--)
    {
        cin >> num >> direct;
        tmp[1] = wheel[1];
        tmp[2] = wheel[2];
        tmp[3] = wheel[3];
        tmp[4] = wheel[4];
        if (num == 1)
        {
            if (direct == 1)
            {
                tmp[1] = (wheel[1] << 1) | (wheel[1] >> 7);
                if (wheel[1][2] != wheel[2][6])
                {
                    tmp[2] = (wheel[2] >> 1) | (wheel[2] << 7);
                    if (wheel[2][2] != wheel[3][6])
                    {
                        tmp[3] = (wheel[3] << 1) | (wheel[3] >> 7);
                        if (wheel[3][2] != wheel[4][6])
                        {
                            tmp[4] = (wheel[4] >> 1) | (wheel[4] << 7);
                        }
                    }
                }
            }
            if (direct == -1)
            {
                tmp[1] = (wheel[1] >> 1) | (wheel[1] << 7);
                if (wheel[1][2] != wheel[2][6])
                {
                    tmp[2] = (wheel[2] << 1) | (wheel[2] >> 7);
                    if (wheel[2][2] != wheel[3][6])
                    {
                        tmp[3] = (wheel[3] >> 1) | (wheel[3] << 7);
                        if (wheel[3][2] != wheel[4][6])
                        {
                            tmp[4] = (wheel[4] << 1) | (wheel[4] >> 7);
                        }
                    }
                }
            }
        }

        if (num == 4)
        {
            if (direct == 1)
            {
                tmp[4] = (wheel[4] << 1) | (wheel[4] >> 7);
                if (wheel[3][2] != wheel[4][6])
                {
                    tmp[3] = (wheel[3] >> 1) | (wheel[3] << 7);
                    if (wheel[2][2] != wheel[3][6])
                    {
                        tmp[2] = (wheel[2] << 1) | (wheel[2] >> 7);
                        if (wheel[1][2] != wheel[2][6])
                        {
                            tmp[1] = (wheel[1] >> 1) | (wheel[1] << 7);
                        }
                    }
                }
            }
            if (direct == -1)
            {
                tmp[4] = (wheel[4] >> 1) | (wheel[4] << 7);
                if (wheel[3][2] != wheel[4][6])
                {
                    tmp[3] = (wheel[3] << 1) | (wheel[3] >> 7);
                    if (wheel[2][2] != wheel[3][6])
                    {
                        tmp[2] = (wheel[2] >> 1) | (wheel[2] << 7);
                        if (wheel[1][2] != wheel[2][6])
                        {
                            tmp[1] = (wheel[1] << 1) | (wheel[1] >> 7);
                        }
                    }
                }
            }
        }
        if (num == 2)
        {
            if (direct == 1)
            {
                tmp[2] = (wheel[2] << 1) | (wheel[2] >> 7);
                if (wheel[1][2] != wheel[2][6])
                {
                    tmp[1] = (wheel[1] >> 1) | (wheel[1] << 7);
                }
                if (wheel[2][2] != wheel[3][6])
                {
                    tmp[3] = (wheel[3] >> 1) | (wheel[3] << 7);
                    if (wheel[3][2] != wheel[4][6])
                    {
                        tmp[4] = (wheel[4] << 1) | (wheel[4] >> 7);
                    }
                }
            }
            if (direct == -1)
            {
                tmp[2] = (wheel[2] >> 1) | (wheel[2] << 7);
                if (wheel[1][2] != wheel[2][6])
                {
                    tmp[1] = (wheel[1] << 1) | (wheel[1] >> 7);
                }
                if (wheel[2][2] != wheel[3][6])
                {
                    tmp[3] = (wheel[3] << 1) | (wheel[3] >> 7);
                    if (wheel[3][2] != wheel[4][6])
                    {
                        tmp[4] = (wheel[4] >> 1) | (wheel[4] << 7);
                    }
                }
            }
        }
        if (num == 3)
        {
            if (direct == 1)
            {
                tmp[3] = (wheel[3] << 1) | (wheel[3] >> 7);
                if (wheel[3][2] != wheel[4][6])
                {
                    tmp[4] = (wheel[4] >> 1) | (wheel[4] << 7);
                }
                if (wheel[2][2] != wheel[3][6])
                {
                    tmp[2] = (wheel[2] >> 1) | (wheel[2] << 7);
                    if (wheel[1][2] != wheel[2][6])
                    {
                        tmp[1] = (wheel[1] << 1) | (wheel[1] >> 7);
                    }
                }
            }
            if (direct == -1)
            {
                tmp[3] = (wheel[3] >> 1) | (wheel[3] << 7);
                if (wheel[3][2] != wheel[4][6])
                {
                    tmp[4] = (wheel[4] << 1) | (wheel[4] >> 7);
                }
                if (wheel[2][2] != wheel[3][6])
                {
                    tmp[2] = (wheel[2] << 1) | (wheel[2] >> 7);
                    if (wheel[1][2] != wheel[2][6])
                    {
                        tmp[1] = (wheel[1] >> 1) | (wheel[1] << 7);
                    }
                }
            }
        }
        wheel[1] = tmp[1];
        wheel[2] = tmp[2];
        wheel[3] = tmp[3];
        wheel[4] = tmp[4];
        // cout << "\n" << wheel[1] << "\n" << wheel[2] << "\n" << wheel[3] <<"\n" << wheel[4] <<"\n";
    }

    cout << (wheel[1][0] + wheel[2][0] * 2 + wheel[3][0] * 4 + wheel[4][0] * 8) << "\n";

    return 0;
}