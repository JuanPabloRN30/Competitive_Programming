#include <bits/stdc++.h>

using namespace std;

vector < bool > mark;
vector < vector < int > > graph;

void dfs( int inicio )
{
  if( inicio == (int)graph.size() )
    return;
  else
  {
    for(int i = 0 ; i < (int)graph[ inicio ].size() ; i++)
    {
      if( !mark[ graph[ inicio ][ i ] ] )
      {
        mark[ graph[ inicio ][ i ] ] = true;
        dfs( graph[ inicio ][ i ] );
      }
    }
  }
}

void solve( )
{
  int cont = 0;
  for(int i = 0 ; i < mark.size() ; i++)
  {
    if( !mark[ i ] )
      cont++;
  }
  printf("%d",cont);
  for(int i = 0 ; i < mark.size() ; i++)
  {
    if( !mark[ i ] )
      printf(" %d",i+1);
  }
  printf("\n");
}

int main()
{
  int n;
  while(scanf("%d",&n) && n)
  {
    graph.assign(n, vector < int >());
    int inicio;
    while( scanf("%d",&inicio) && inicio )
    {
      int destino;
      while( scanf("%d",&destino) && destino )
        graph[ inicio-1 ].push_back(destino-1);
    }
    int query;
    scanf("%d",&query);
    while( query-- )
    {
      scanf("%d",&inicio);
      mark.assign( n, false );
      dfs( inicio-1 );
      solve();
    }
  }
  return 0;
}
