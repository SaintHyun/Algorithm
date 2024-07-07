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

    priority_queue<int, vector<int>, greater<int>> min_heap;
    int n, i;
    cin >> n;
    for(i=0; i<n; i++)
    {
        int tmp; 
        cin >> tmp;
        if(tmp == 0)
        {
            if(min_heap.empty()) cout << "0\n";
            else 
            {
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        }
        else
        {
            min_heap.push(tmp);
        }

    }    
}