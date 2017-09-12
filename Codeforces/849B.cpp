#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair < int , int > ii;

struct TPoint
{
    int x,y;
};

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    TPoint arr[10000];
    cin >> n;
    vector < vector < ii > > slope(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i].y;
        arr[i].x = i;
    }
    map < ii , int > mapa;
    map < ii , int >::iterator it;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = i+1 ; j < n ; j++)
        {
            int arriba = arr[j].y - arr[i].y;
            int abajo = arr[j].x - arr[i].x;
            int ans = __gcd(arriba,abajo);
            while( ans != 1 )
            {
                arriba /= ans;
                abajo /= ans;
                ans = __gcd(arriba,abajo);
            }
            slope[i].push_back( ii(arriba, abajo));
            mapa[ii(arriba,abajo)]++;
        }
    }

    int may = 0;
    bool flag = true;
    bool solo = false;
    ii ans;
    for(it = mapa.begin() ; it != mapa.end() ; it++)
        if(it->second > may) may = it->second, ans = it->first;
    vector < bool > mark(n,false);
    for(int i = 0 ; i < n ; i++)
    {
        int c = 0, aux = i+1;
        for(int j = 0 ; j < (int)slope[i].size() ; j++, aux++)
        {
            if(slope[i][j] == ans)
                mark[i] = 1, mark[aux] = 1, c++;
        }
        if(c == n-1) flag = false;
        if(c == n-2) solo = true;
    }
    if(!solo)
        for(int i = 0 ; i < n ; i++)
            if(!mark[i]) flag = false;
    if(flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}
