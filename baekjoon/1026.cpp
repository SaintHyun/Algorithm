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

    int n, i, tmp, ans = 0;
    vector<int> a, b;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (i = 0; i < n; i++)
    {
        cin >> tmp;
        b.push_back(tmp);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<int>());

    for (i = 0; i < n; i++)
    {
        ans += a[i] * b[i];
    }
    cout << ans << "\n";

    return 0;
}