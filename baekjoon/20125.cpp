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

    int n, i, j, legX;
    int headX = 0, headY = 0, leftArm = 0, rightArm = 0, waist = 0, leftLeg = 0, rightLeg = 0;
    char cookie[1010][1010];

    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> cookie[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (cookie[i][j] == '*')
            {
                headX = i + 1;
                headY = j;
                i = n;
                break;
            }
        }
    }
    for (j = 0; j < headY; j++)
    {
        if (cookie[headX][j] == '*')
            leftArm++;
    }
    for (j = headY + 1; j < n; j++)
    {
        if (cookie[headX][j] == '*')
            rightArm++;
    }

    for (i = headX + 1; i < n; i++)
    {
        if (cookie[i][headY] == '*')
            waist++;
        else
            break;
    }
    legX = i;
    for (i = legX; i < n; i++)
    {
        if (cookie[i][headY - 1] == '*')
            leftLeg++;
        if (cookie[i][headY + 1] == '*')
            rightLeg++;
    }
    cout << headX + 1 << " " << headY + 1 << "\n";
    cout << leftArm << " " << rightArm << " " << waist << " " << leftLeg << " " << rightLeg << "\n";

    return 0;
}