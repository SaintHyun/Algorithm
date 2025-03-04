#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int n;
int num[110], opr[4];
int maxx = INT_MIN, minn = INT_MAX;

void dfs(int idx, int result, int add, int sub, int mul, int div)
{
    if (idx == n + 1)
    {
        if (result > maxx)
            maxx = result;
        if (result < minn)
            minn = result;
        return;
    }
    if (add > 0)
    {
        dfs(idx + 1, result + num[idx], add - 1, sub, mul, div);
    }
    if (sub > 0)
    {
        dfs(idx + 1, result - num[idx], add, sub - 1, mul, div);
    }
    if (mul > 0)
    {
        dfs(idx + 1, result * num[idx], add, sub, mul - 1, div);
    }
    if (div > 0)
    {
        dfs(idx + 1, result / num[idx], add, sub, mul, div - 1);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;

    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    for (i = 0; i < 4; i++)
    {
        cin >> opr[i];
    }

    dfs(2, num[1], opr[0], opr[1], opr[2], opr[3]);

    cout << maxx << "\n" << minn << "\n";

    return 0;
}