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

    set<string> people;
    vector<string> ans;
    int n, m, i; 
    cin >> n >> m;
    for(i=0; i<n; i++)
    {
        string tmp;
        cin >> tmp;
        people.insert(tmp);
    }
    for(i=0; i<m; i++)
    {
        string tmp;
        cin >> tmp;
        if(people.find(tmp) != people.end())
        {
            ans.push_back(tmp);
        } 
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(i=0; i<ans.size(); i++)
    {
        cout << ans[i] << "\n";
    }
}