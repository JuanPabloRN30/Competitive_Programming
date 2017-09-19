#include <bits/stdc++.h>

using namespace std;

char matriz[ 25 ][ 25 ];
int m,n;

int di[ 4 ] = { -1,0,0,1 };
int dj[ 4 ] = { 0,-1,1,0};

bool in_map( int i, int j )
{
  return i>= 0 && i < m && j >= 0 && j < n;
}

void imprimir()
{
  for( int i = 0 ; i < m ; i++ )
  {
    for( int j = 0 ; j < n ; j++ )
    {
      cout << matriz[ i ][ j ] << " ";
    }
    cout << endl;
  }
}

int dfs( pair < int , int > inicio, char caracter )
{
  matriz[ inicio.first ][ inicio.second ] = caracter+1;
  int acum = 1;
  // cout << endl;
  // imprimir();
  // cout << endl;
  for( int i = 0 ; i < 4 ; i++ )
  {
    int currenti = di[ i ] + inicio.first;
    int currentj = dj[ i ] + inicio.second;
    if( in_map( currenti, currentj ) && matriz[ currenti ][ currentj ] == caracter )
    {
      acum += dfs( make_pair( currenti, currentj ),caracter );
    }
  }
  if( inicio.second == n-1 )
  {
    for( int i = 0 ; i < 3 ; i++ )
    {
      int currenti = inicio.first;
      int currentj = 0;
      if( in_map( currenti, currentj ) && matriz[ currenti ][ currentj ] == caracter )
      {
        acum += dfs( make_pair( currenti, currentj ),caracter );
      }
    }
  }
  if( inicio.second == 0 )
  {
    for( int i = 0 ; i < 3 ; i++ )
    {
      int currenti = inicio.first;
      int currentj = n-1;
      if( in_map( currenti, currentj ) && matriz[ currenti ][ currentj ] == caracter )
      {
        acum += dfs( make_pair( currenti, currentj ),caracter );
      }
    }
  }
//  cout << acum << endl;
  return acum;
}


int main()
{

  while( scanf("%d%d",&m,&n) != EOF )
  {
    for( int i = 0 ; i < m ; i++ )
    {
      for( int j = 0 ; j < n ; j++ )
      {
        scanf(" %c",&matriz[ i ][ j ]);
      }
    }
    pair < int , int > posicion;
    scanf("%d%d",&posicion.first,&posicion.second );
    char caracter = matriz[ posicion.first ][ posicion.second ];
    dfs( posicion, caracter );
    int maxi = 0;
    for( int i = 0 ; i < m ; i++ )
    {
      for( int j = 0 ; j < n ; j++ )
      {
        if( matriz[ i ][ j ] == caracter )
          maxi = max(dfs( make_pair( i,j ), caracter ),maxi);
      }
    }
    printf("%d\n",maxi);
  }

  return 0;
}
