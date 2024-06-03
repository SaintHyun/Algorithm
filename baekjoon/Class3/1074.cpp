#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int x, y, cnt, ans;
bool flag = false;

void divide(int s, int w, int size)
{
    if (size == 1 && s == x && w == y)
    {
        flag = true;
        ans = cnt;
        return;
    }
    if (flag == false && size != 1)
    {
        int tmp = size / 2;
        if (x <= s - tmp && y <= w - tmp)
        {
            divide(s - tmp, w - tmp, tmp);
        }
        else if (x <= s - tmp && y > w - tmp)
        {
            cnt += tmp * tmp;
            divide(s - tmp, w, tmp);
        }
        else if (x > s - tmp && y <= w - tmp)
        {
            cnt += tmp * tmp * 2;
            divide(s, w - tmp, tmp);
        }
        else
        {
            cnt += tmp * tmp * 3;
            divide(s, w, tmp);
        }
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

    int n;
    cin >> n >> x >> y;
    x++;
    y++;

    n = 1 << n;

    divide(n, n, n);
    cout << ans << "\n";
}