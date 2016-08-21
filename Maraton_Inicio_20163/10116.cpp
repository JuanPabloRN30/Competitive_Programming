#include <bits/stdc++.h>

using namespace std;

int n,m;

bool in( int currenti, int currentj )
{
  return currenti >= 0 && currenti < n && currentj >= 0 && currentj < m;
}

int main()
{
  int entra;
  while( scanf("%d%d%d",&n,&m,&entra ) && (n+m+entra) )
  {
    vector < vector < char > > matriz(n, vector < char > (m));
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < m ; j++)
      {
        cin >> matriz[ i ][ j ];
      }
    }

    pair < int , int > inicio = make_pair(0,entra-1);
    vector < vector < int > > mark(n, vector < int > (m,-1));
    mark[ inicio.first ][ inicio.second ] = 1;
    int salida = 0;
    int cont = 1;
    while( !salida )
    {
      switch ( matriz[ inicio.first ][ inicio.second ] )
      {
        case 'N':
          inicio = make_pair( inicio.first-1, inicio.second );
        break;
        case 'S':
          inicio = make_pair( inicio.first+1, inicio.second );
        break;
        case 'E':
          inicio = make_pair( inicio.first, inicio.second+1 );
        break;
        case 'W':
          inicio = make_pair( inicio.first, inicio.second-1 );
        break;
      }
      cont++;
      if( in(inicio.first,inicio.second) )
      {
        if( mark[ inicio.first ][ inicio.second ] == -1)
          mark[ inicio.first ][ inicio.second ] = cont;
        else
          salida = 1;
      }
      else
        salida = 2;
    }
    if(salida == 2)
      printf("%d step(s) to exit\n",cont-1);
    else
      printf("%d step(s) before a loop of %d step(s)\n",mark[ inicio.first ][ inicio.second ]-1,abs(mark[ inicio.first ][ inicio.second ] - cont));
  }

  return 0;
}
