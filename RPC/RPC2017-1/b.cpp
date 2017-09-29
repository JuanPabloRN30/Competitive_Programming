#include<iostream>
#include<cstring>

using namespace std;
char mat[30][30];
int dp[30][30];
int cant_w,n;
int dfil[] = {-1,-1,1,1};
int dcol[] = {-1,1,-1,1};

bool in(int i, int j)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

int backtrack(int i, int j)
{
    if(dp[i][j] != -1) return dp[i][j];
    int aux = 0;
    int current_i, current_j, current_ii, current_jj;
    for(int k = 0 ; k < 4 ; k++)
    {
        current_i = dfil[k]+i;
        current_j = dcol[k]+j;
        if(in(current_i, current_j) && mat[current_i][current_j] == 'W')
        {
            current_ii = current_i + dfil[k];
            current_jj = current_j + dcol[k];
            mat[current_i][current_j] = '.';
            if(in(current_ii, current_jj) && (mat[current_ii][current_jj] == '.' || mat[current_ii][current_jj] == '_'))
            {
                mat[current_ii][current_jj] = 'B';
                mat[i][j] = '.';
                aux = max(aux,backtrack(current_ii, current_jj)+1);
                mat[i][j] = 'B';
                mat[current_ii][current_jj] = '.';
            }
            mat[current_i][current_j] = 'W';
            if(aux == cant_w)
            {
                dp[i][j] = cant_w;
                return cant_w;
            }
        }
    }
    return dp[i][j] = aux;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cant_w = 0;
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            cin >> mat[i][j];
            cant_w += (mat[i][j] == 'W');
        }
    }
    int ans = 0, aux;
    pair < int , int > pos_ans;
    memset(dp, -1, sizeof dp);
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(mat[i][j] == 'B')
            {
                aux = backtrack(i, j);
                ans += (aux == cant_w);
                if(aux == cant_w) pos_ans = make_pair(i,j);
            }
        }
    }
    if(ans == 0) cout << "None\n";
    else if(ans > 1) cout << "Multiple\n";
    else{
        cout << (char)(pos_ans.second+'a') << n-pos_ans.first << '\n';
    }
    return 0;
}
