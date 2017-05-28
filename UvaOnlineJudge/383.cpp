#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > graph;

int bfs(int inicio, int destino)
{
  queue < pair < int , int > > q;
  vector < int > mark(graph.size(), false);
  q.push( make_pair( inicio, 0 ) );
  mark[ inicio ] = true;
  while( !q.empty() )
  {
    pair < int , int > actual = q.front();
    if( actual.first == destino )
      return actual.second;
    q.pop();
    for(int i = 0 ; i < (int)graph[ actual.first ].size() ; i++)
    {
      if( !mark[ graph[ actual.first ][ i ] ])
      {
        mark[ graph[ actual.first ][ i ] ] = true;
        q.push( make_pair( graph[ actual.first ][ i ], actual.second+100 ) );
      }
    }
  }
  return -1;
}

int main()
{
  int cases;
  scanf("%d",&cases);
  int cont = 1;
  printf("SHIPPING ROUTES OUTPUT\n");
  while( cases-- )
  {
    printf("\n");
    printf("DATA SET  %d\n\n",cont++);
    int m,n,p,costo;
    scanf("%d%d%d",&m,&n,&p);
    string letras,letras1;
    map < string , int > mapa;
    graph.assign( m, vector < int >() );
    for(int i = 0 ; i < m ; i++)
    {
      cin >> letras;
      mapa[ letras ] = i;
    }
    for(int i = 0 ; i < n ; i++)
    {
      cin >> letras >> letras1;
      graph[ mapa[ letras ] ].push_back( mapa[ letras1 ] );
      graph[ mapa[ letras1 ] ].push_back( mapa[ letras ] );
    }
    for(int i = 0 ; i < p ; i++)
    {
      scanf("%d",&costo);
      cin >> letras >> letras1;
      int resultado = bfs( mapa[ letras ], mapa[ letras1 ] );
      if( resultado == -1 )
        printf("NO SHIPMENT POSSIBLE\n");
      else
        printf("$%d\n",resultado*costo);
    }
  }
  printf("\nEND OF OUTPUT\n");


  return 0;
}
