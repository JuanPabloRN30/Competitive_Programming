#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > graph;
vector < int > answ;
vector < bool > mark2;

void dfs( int inicio )
{
    mark2[ inicio ] = true;
    for(int i = 0 ; i < (int)graph[inicio].size() ; i++)
    {
      if( !mark2[ graph[ inicio ][ i ] ] )
        dfs( graph[ inicio ][ i ] );
    }
    answ.push_back( inicio );
}

int main()
{
  int n,m;
  while( scanf("%d%d",&n,&m) && (n+m) )
  {
    graph.assign( n, vector < int >() );
    answ.clear();
    vector < bool > mark(n,false);
    mark2.assign(n,false);
    int x,y;
    for(int i = 0 ; i < m ; i++)
    {
      scanf("%d%d",&x,&y);
      graph[ x-1 ].push_back(y-1);
      mark[ y-1 ] = true;
    }

    for(int i = 0 ; i < n ; i++)
    {
      if( !mark[ i ])
        dfs( i );
    }
    for(int i = answ.size() -1 ; i >= 0 ; i--)
    {
      if( i == (int)answ.size()-1 )
        printf("%d",answ[i]+1);
      else
        printf(" %d",answ[i]+1);
    }
    printf("\n");
  }


  return 0;
}
