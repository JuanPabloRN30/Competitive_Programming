#include<bits/stdc++.h>

using namespace std;

vector < vector < int > > graph;

int bfs(int inicio, int ttl)
{
  queue < pair < int , int > > q;
  vector < bool > mark( graph.size(), false );
  mark[ inicio ] = true;
  q.push( make_pair( inicio,0 ) );
  int cont = 0;
  while( !q.empty() )
  {
    int actual = q.front().first;
    int nivel = q.front().second;
    q.pop();
    if( nivel > ttl )
    {
      // cout << actual<< " "<< nivel << endl;
      cont++;
    }
    for(int i = 0 ; i < (int)graph[ actual ].size() ; i++)
    {
      if( !mark[ graph[ actual ][ i ] ] )
      {
        mark[ graph[ actual ][ i ] ] = true;
        q.push( make_pair(graph[ actual ][ i ],nivel+1) );
      }
    }
  }
  return cont;
}

int main()
{
  int nc;
  int casos = 1;
  while( scanf("%d",&nc) && nc )
  {
    map < int , int > mapa;
    int first,second;
    int consecutivo = 0;
    graph.assign( 31, vector < int >() );
    for(int i = 0 ; i < nc ; i++)
    {
      scanf("%d%d",&first,&second);
      if( mapa.find( first ) == mapa.end())
        mapa[ first ] = consecutivo++;
      if( mapa.find( second ) == mapa.end())
        mapa[ second ] = consecutivo++;
      graph[ mapa[ first ] ].push_back( mapa[ second ] );
      graph[ mapa[ second ] ].push_back( mapa[ first ] );
    }
    // map < int , int >::iterator it;
    // for( it = mapa.begin() ; it != mapa.end() ; it++)
    // {
    //   cout << it->first << " " << it->second << endl;
    // }
    int inicio,ttl;
    while( scanf("%d%d",&inicio,&ttl ) && (inicio+ttl) )
    {
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",casos++,bfs( mapa[ inicio ],ttl),inicio,ttl);
    }
  }
  return 0;
}
