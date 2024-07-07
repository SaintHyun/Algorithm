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

    int n, m, i;
    int current_position, current_count;
    bool visited[100010] = {false};
    queue<pair<int, int>> q;
    cin >> n >> m;
    q.push({n, 0});
    visited[n] = true;
    while (!q.empty())
    {
        current_position = q.front().first;
        current_count = q.front().second;
        q.pop();

        if (current_position == m)
        {
            cout << current_count << "\n";
            return 0;
        }
        if (current_position - 1 >= 0 && current_position - 1 <= 100000 && visited[current_position - 1] == false)
        {
            q.push({current_position - 1, current_count + 1});
            visited[current_position - 1] = true;
        } 
        if (current_position + 1 >= 0 && current_position + 1 <= 100000 && visited[current_position + 1] == false)
        {
            q.push({current_position + 1, current_count + 1});
            visited[current_position + 1] = true;
        } 
        if (current_position * 2 >= 0 && current_position * 2 <= 100000 && visited[current_position * 2] == false)
        {
            q.push({current_position * 2, current_count + 1});
            visited[current_position * 2] = true;
        } 
    }
}