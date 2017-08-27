#include <iostream>

using namespace std;

typedef long long ll;

ll comb[100][100];
void precalc()
{
    for(int i = 0 ; i <= 60 ; i++)
    {
        comb[i][0] = comb[i][i] = 1;
        for(int k = 1 ; k < i ; k++)
            comb[i][k] = comb[i-1][k] + comb[i-1][k-1];
    }
}

int main()
{
    int n,m, cont_w, cont_b;
    bool mat[100][100];
    precalc();
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < m ; j++)
            cin >> mat[i][j];
    ll tot = n * m;
    for(int i = 0 ; i < n ; i++)
    {
        cont_b = 0;
        cont_w = 0;
        for(int j = 0 ; j < m ; j++)
        {
            if(mat[i][j]) cont_b++;
            if(!mat[i][j]) cont_w++;
        }
        for(int i = 2 ; i <= cont_b ; i++)
            tot+= comb[cont_b][i];
        for(int i = 2 ; i <= cont_w ; i++)
            tot+= comb[cont_w][i];

    }
    for(int i = 0 ; i < m ; i++)
    {
        cont_b = 0;
        cont_w = 0;
        for(int j = 0 ; j < n ; j++)
        {
            if(mat[j][i]) cont_b++;
            if(!mat[j][i]) cont_w++;
        }
        if(cont_b > 1)
            for(int i = 2 ; i <= cont_b ; i++)
                tot+= comb[cont_b][i];
        if(cont_w > 1)
            for(int i = 2 ; i <= cont_w ; i++)
                tot+= comb[cont_w][i];
    }
    cout << tot << '\n';
    return 0;
}
