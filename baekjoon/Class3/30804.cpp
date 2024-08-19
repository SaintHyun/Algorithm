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

    int n, fruit[200001], used[10] = {0}, i, left = 1, right, cnt = 0, ans = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> fruit[i];
    }
    for (right = 1; right <= n; right++)
    {
        used[fruit[right]] += 1;
        if (used[fruit[right]] == 1)
            cnt++;
        while (cnt > 2)
        {
            used[fruit[left]] -= 1;
            if (used[fruit[left]] == 0)
                cnt--;
            left++;
        }
        ans = max(ans, right - left + 1);
    }
    cout << ans << "\n";
}