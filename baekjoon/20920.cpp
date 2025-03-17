#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool compare(pair<string,int> a, pair<string, int> b)
{
    if(a.second > b.second) return true;
    else if(a.second == b.second && a.first.length() > b.first.length()) return true;
    else if(a.second == b.second && a.first.length() == b.first.length() && a.first < b.first) return true;
    return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, i;
    map<string,int> word;
    string tmp;
    cin >> n >> m;
    for(i=0; i<n; i++)
    {
        cin >> tmp;
        if(tmp.length() >= m)
        {
            word[tmp] += 1;
        }
    }

    vector<pair<string,int>> vec(word.begin(), word.end());
    sort(vec.begin(), vec.end(), compare);

    for(i=0; i<vec.size(); i++)
    {
        cout << vec[i].first << "\n";
    }

    return 0;
}