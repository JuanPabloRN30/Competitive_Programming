#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef pair < int , pair < int , int > > iii;
int n,m;
char mat[510][510];
bool visited[510][510];

int dfil[] = {-1,1,0,0};
int dcol[] = {0,0,-1,1};

bool in(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < m;
}

int bfs(int x, int y)
{
    memset(visited, 0, sizeof visited);
    queue < iii > q;
    q.push(iii(x,make_pair(y,0)));
    visited[x][y]=1;
    int level = 0;
    while(!q.empty())
    {
        iii current = q.front(); q.pop();
        level = current.second.second;
        int pasos = mat[current.first][current.second.first] - '0';
        for(int i = 0 ; i < 4 ; i++)
        {
            int curr_i = dfil[i]*pasos + current.first;
            int curr_j = dcol[i]*pasos + current.second.first;
            if(in(curr_i,curr_j) && !visited[curr_i][curr_j])
            {
                visited[curr_i][curr_j] = 1;
                if(curr_i == n-1 && curr_j == m-1) return level+1;
                q.push(iii(curr_i,make_pair(curr_j,level+1)));
            }
        }
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> mat[i][j];
    int ans = bfs(0,0);
    if(ans == -1) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
    return 0;
}
