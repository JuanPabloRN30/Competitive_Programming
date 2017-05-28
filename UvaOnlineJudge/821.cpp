#include <bits/stdc++.h>

using namespace std;

const double INF = 1000000000.0;
double graph[ 115 ][ 115 ];

void floyd_warshall()
{
  for( int k = 0 ; k < 110 ; k++ )
    for( int i = 0 ; i < 110 ; i++)
      for( int j = 0 ; j < 110 ; j++ )
        graph[ i ][ j ] = min( graph[ i ][ j ], graph[ i ][ k ] + graph[ k ][ j ] );

}

int main()
{
  int a,b;
  int caso = 1;
  while( scanf("%d%d",&a,&b) && (a+b) )
  {
    for( int i = 0 ; i < 110 ; i++ )
    {
      for( int j = 0 ; j < 110 ; j++ )
      {
        graph[ i ][ j ] = INF;
      }
    }
    graph[ a ][ b ] = 1.0;
    while( scanf("%d%d",&a,&b) && (a+b) )
    {
      graph[ a ][ b ] = 1.0;
    }
    floyd_warshall();
    double acum = 0.0;
    double cont = 0.0;
    for( int i = 0 ; i < 110 ; i++ )
    {
      for( int j = 0 ; j < 110 ; j++ )
      {
        if( graph[ i ][ j ] != INF && i != j )
        {
          acum += graph[ i ][ j ];
          cont++;
        }
      }
    }
    double result = acum/cont;
    printf("Case %d: average length between pages = %.3lf clicks\n",caso,result );
    ++caso;
  }

  return 0;
}
