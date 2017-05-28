#include <bits/stdc++.h>

using namespace std;

int chessboard[ 8 ][ 8 ];
int mem[ 8 ];

bool can_put( int row, int column )
{
  for(int i = 0 ; i < 8 ; i++)
  {
    if( i == row && mem[ i ] != -1 )
      return false;
    if( column == mem[ i ] )
      return false;
    // FALTA DIAGONAL
  }
}

int maxima_suma(  )
{
  for(int i = 0 ; i < 8 ; i++)
  {
    
  }
}

int main()
{
  int k;
  scanf("%d",&k);
  while( k-- )
  {
    for(int i = 0 ; i < 8 ; i++)
    {
      for(int j = 0 ; j < 8 ; j++)
      {
          scanf("%d",&chessboard[ i ][ j ]);
      }
    }
  }


  return 0;
}
