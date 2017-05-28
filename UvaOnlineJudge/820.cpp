#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;
const int INF = 1e9;

int mf, f, s, t;
vector < vector < int > >res;
vector < int > p;
void augment(int v, int minEdge) {
  if (v == s)
  {
    f = minEdge; return;
  }
  else if (p[v] != -1)
  {
    augment(p[v], min(minEdge, res[p[v]][v]));
    res[p[v]][v] -= f;
    res[v][p[v]] += f;
  }
}

int main()
{
  int n;
  int casos = 1;
  while( scanf("%d",&n) && n )
  {
    mf = 0;
    printf("Network %d\n",casos++);
    int cantidad;
    scanf("%d%d%d",&s,&t,&cantidad);
    s--;
    t--;
    int origen,destiny,costo;
    res.assign( n, vector < int > (n,0) );
    for(int i = 0 ; i < cantidad ; i++)
    {
      scanf("%d%d%d",&origen,&destiny,&costo);
      res[ origen-1 ][destiny-1] += costo;
      res[ destiny-1 ][origen-1] += costo;
    }
    while (1) {
      f = 0;
      vector < bool > dist(n, false);
      dist[s] = true;
      queue<int> q;
      q.push(s);
      p.assign(n, -1);
      while (!q.empty())
      {
        int u = q.front();
        q.pop();
        if (u == t)
          break;
        for (int v = 0; v < n; v++)
        {
          if (res[u][v] > 0 && !dist[v] )
          {
            dist[v] = true;
            q.push(v);
            p[v] = u;
          }
        }
      }
      augment(t, INF);
      if (f == 0) break;
      mf += f;
    }
    printf("The bandwidth is %d.\n",mf);
    printf("\n");
  }
  return 0;
}
