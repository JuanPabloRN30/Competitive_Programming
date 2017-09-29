#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

ll mat[200][200];
ll aux_mat[200][200];
int n,m;

int dfil[] = {-1,-1,-1,0,0,1,1,1};
int dcol[] = {-1,0,1,-1,1,-1,0,1};

ll average(int i, int j)
{
    ll sum = mat[i][j];
    int curr_i, curr_j;
    for(int k = 0 ; k < 8 ; k++)
    {
        if(dfil[k]+i < 0) curr_i = (dfil[k]+i+n)%n;
        else curr_i = (dfil[k]+i)%n;
        if(dcol[k]+j < 0) curr_j = (dcol[k]+j+m)%m;
        else curr_j = (dcol[k]+j)%m;
        sum += mat[curr_i][curr_j];
    }
    return sum;
}

void blur()
{
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            aux_mat[i][j] = average(i,j);
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            mat[i][j] = aux_mat[i][j];
}

int ans()
{
    set < int > ans;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
            ans.insert(mat[i][j]);
    }
    return ans.size();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int b;
    cin >> m >> n >> b;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> mat[i][j];
    while(b--)
        blur();
    cout << ans() << endl;
    return 0;
}
