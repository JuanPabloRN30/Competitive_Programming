#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair < int, int > ii;

vector < int > id;
vector < int > sz;

void iniciar(int n)
{
    id.assign(n, 0);
    sz.assign(n, 1);
    for(int i = 0 ; i < n ; i++)
        id[i] = i;
}

int root(int i)
{
    while(i != id[i])
    {
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

bool connected(int i, int j)
{
    return root(i) == root(j);
}

void unir(int p, int q)
{
    int i = root(p);
    int j = root(q);
    if(i == j) return;
    if(sz[i] < sz[j])
    {
        id[i] = j;
        sz[j]+= sz[i];
    }
    else
    {
        id[j] = i;
        sz[i]+=sz[j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ii sequence[100100];
    int n;
    cin >> n;
    iniciar(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> sequence[i].first;
        sequence[i].second = i;
    }
    sort(sequence, sequence + n);
    for(int i = 0 ; i < n ; i++)
        unir(i, sequence[i].second);
    int cant_disj = 0;
    vector < bool > mark1(n, false);
    vector < vector < int > > ans(n, vector < int >());
    for(int i = 0 ; i < n ; i++)
        ans[ root(i) ].push_back(i+1);
    for(int i = 0 ; i < n ; i++)
      cant_disj += (ans[i].size() ? 1 : 0);
    cout << cant_disj << '\n';
    for(int i = 0 ; i < (int)ans.size() ; i++)
    {
      if(ans[i].size())
      {
        cout << ans[i].size() << ' ';
        for(int j = 0 ; j < (int)ans[i].size() ; j++)
        {
          if(j) cout << ' ';
          cout << ans[i][j];
        }
        cout << '\n';
      }
    }
    return 0;
}
