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

    int n, size[6], t, p, i;
    int anst = 0, ansp1 = 0, ansp2 = 0;
    cin >> n;
    for (i = 0; i < 6; i++)
    {
        cin >> size[i];
    }
    cin >> t >> p;
    for (i = 0; i < 6; i++)
    {
        if (size[i] % t != 0)
            anst += size[i] / t + 1;
        else
            anst += size[i] / t;
    }
    ansp1 = n / p;
    ansp2 = n % p;
    cout << anst << "\n" << ansp1 << " " << ansp2 << "\n";
}