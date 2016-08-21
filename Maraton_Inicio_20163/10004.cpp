#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < vector < int > > graph;

bool bfs( int origen )
{
  queue < int > q;
  int color[200];
  for(int i = 0 ; i < 200 ; i++)
    color[ i ] = -1;
  q.push( origen );
  color[ origen ] = 1;
  while( !q.empty() )
  {
    int current = q.front();
    q.pop();
    for(int i = 0 ; i < graph[ current ].size() ; i++)
    {
      int hijito = graph[ current ][i];
      if( color[ hijito ] == -1 )
      {
        color[hijito] = 1-color[ current ];
        q.push( hijito );
      }
      else
      {
        if( color[ hijito ] == color[current] )
        {
          return false;
        }
      }
    }
  }
  return true;

}

int main()
{
  int n;
  while( scanf("%d",&n) && n )
  {
    int e;
    int o,d;
    scanf("%d",&e);
    graph.assign(n , vector < int > ());
    for(int i = 0 ; i < e ; i++)
    {
      scanf("%d%d",&o,&d);
      graph[ o ].push_back( d );
      graph[ d ].push_back( o );
    }
    printf("%s\n", ( bfs(0) ? "BICOLORABLE." : "NOT BICOLORABLE." ) );
  }


  return 0;
}
