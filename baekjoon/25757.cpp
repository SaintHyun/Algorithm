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

    int n, i;
    char type;
    set<string> people;
    string tmp;

    cin >> n >> type;
    for(i=0; i<n; i++)
    {
        cin >> tmp;
        people.insert(tmp);
    }
    switch (type)
    {
        case 'Y':
            cout << people.size() << "\n";
            break;
        case 'F':
            cout << people.size() / 2 << "\n";
            break;
        case 'O':
            cout << people.size() / 3 << "\n";
            break;
        default:
            break;
    }

    return 0;
}