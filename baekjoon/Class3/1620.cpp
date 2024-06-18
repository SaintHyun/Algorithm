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

    map<int, string> pokemon1;
    map<string, int> pokemon2;
    int n, m, i;
    cin >> n >> m;
    for(i=1; i<=n; i++)
    {
        string tmp;
        cin >> tmp;
        pokemon1.insert({i, tmp});
        pokemon2.insert({tmp, i});
    }
    for(i=1; i<=m; i++)
    {
        string tmp1;
        int tmp2;
        cin >> tmp1;
        if(tmp1[0] >= '0' && tmp1[0] <= '9')
        {
            tmp2 = stoi(tmp1);
            cout << pokemon1.find(tmp2)->second << "\n";
        }
        else
        {
            cout << pokemon2.find(tmp1)->second << "\n";
        }
    }
}