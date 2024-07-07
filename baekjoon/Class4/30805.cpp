#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

bool compare(pair<int,int>a, pair<int,int>b)
{
    if(a.first > b.first) return true;
    if(a.first == b.first) return a.second<b.second;
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

    int n, m;
    vector<pair<int, int>> A, B;
    vector<int> ans;
    int i,j, curidxA=-1, curidxB=-1;
    cin >> n;
    for(i=0; i<n; i++)
    {
        int tmp;
        cin >> tmp;
        A.push_back(make_pair(tmp, i));
    }
    cin >> m;
    for(j=0; j<m; j++)
    {
        int tmp;
        cin >> tmp;
        B.push_back(make_pair(tmp, j));
    }
    sort(A.begin(), A.end(), compare);
    sort(B.begin(), B.end(), compare);

    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(B[j].first == A[i].first)
            {
                if(curidxA < A[i].second && curidxB < B[j].second)
                {
                    curidxA = A[i].second;
                    curidxB = B[j].second;
                    ans.push_back(A[i].first);
                    break;
                }
            }
        }
    }
    cout << ans.size() << "\n";
    for(i=0; i<ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
}