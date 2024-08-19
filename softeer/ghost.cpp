#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

char tmp;
int maze[1010][1010], n, m, i, j;
int test[1010][1010];
int next_y, next_x;
int namwoo_cost=987654321, ghost_cost = 987654321;
int dy[4] = {0, 0, 1, -1}, dx[4] = {1, -1, 0, 0};
int visited[1010][1010];
int desty, destx;
vector<pair<int, int>> ghost;
queue<pair<pair<int,int>,int>> q;

int cury, curx, curcnt;
queue<pair<pair<int,int>,int>> ghost_q;
int ghost_visited[1010][1010];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n>> m;
    
    
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            test[i][j] = 987654321;
            cin >> tmp;
            switch(tmp)
            {
                case '.' :
                    maze[i][j] = 0;
                    break;
                case '#' :
                    maze[i][j] = 1;
                    break;
                case 'G' :
                    maze[i][j] = 2;
                    ghost_q.push({{i,j},0});
                    ghost_visited[i][j] = 1;
                    break;
                case 'D' :
                    maze[i][j] = 3;
                    desty = i;
                    destx = j;
                    break;
                case 'N' :
                    q.push({{i,j},0});
                    visited[i][j] = 1;
                    break;
            }
        }
    }
    
    while(!ghost_q.empty())
    {
        cury = ghost_q.front().first.first;
        curx = ghost_q.front().first.second;
        curcnt = ghost_q.front().second;
        ghost_q.pop();

        for(i=0; i<4; i++)
        {
            next_y = cury + dy[i];
            next_x = curx + dx[i];
            if((next_y>=1 && next_y<=n && next_x >=1 && next_x <=m ) && ghost_visited[next_y][next_x] == 0)
            {
                ghost_visited[next_y][next_x] = ghost_visited[cury][curx]+1;
                ghost_q.push({{next_y,next_x,},curcnt+1});
            }
        }
    }
    

    while(!q.empty())
    {
        cury = q.front().first.first;
        curx = q.front().first.second;
        curcnt = q.front().second;
        q.pop();
        for(i=0; i<4; i++)
        {
            next_y = cury + dy[i];
            next_x = curx + dx[i];
            if((next_y>=1 && next_y<=n && next_x >=1 && next_x <=m ) && (maze[next_y][next_x] != 1) && visited[next_y][next_x] == 0 && visited[cury][curx] + 1 < ghost_visited[next_y][next_x])
            {
                visited[next_y][next_x] = visited[cury][curx]+1;
                q.push({{next_y,next_x,},curcnt+1});
            }
        }
    }
    if(visited[desty][destx] == 0) cout << "No\n";
    else cout << "Yes\n";
}