#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  int cont = 1;
  scanf("%d",&t);
  while( t-- )
  {
    int n,m,dinero;
    scanf("%d%d%d",&n,&m,&dinero);
    int matriz[ n ][ m ];
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < m ; j++)
      {
        scanf("%d",&matriz[ i ][ j ] );
        if( i > 0 ) matriz[ i ][ j ] += matriz[ i - 1 ][ j ];
        if( j > 0 ) matriz[ i ][ j ] += matriz[ i ][ j - 1 ];
        if( i > 0 && j > 0 ) matriz[ i ][ j ] -= matriz[ i - 1 ][ j - 1 ];
      }
    }
    int maxArea = 0;
    int maxValor = 0;
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < m ; j++)
      {
        for(int k = i ; k < n ; k++)
        {
          for(int l = j ; l < m ; l++)
          {
            int subRect = matriz[ k ][ l ];
            if( i > 0 ) subRect -= matriz[ i - 1 ][ l ];
            if( j > 0 ) subRect -= matriz[ k ][ j - 1 ];
            if( i > 0 && j > 0 ) subRect += matriz[ i - 1 ][ j - 1 ];
            if( (k-i+1)*(l-j+1) > maxArea )
            {
              if( subRect <= dinero )
              {
                maxArea = (k-i+1)*(l-j+1);
                maxValor = subRect;
              }
            }
            else if( (k-i+1)*(l-j+1) == maxArea)
            {
              if( subRect <= dinero )
              {
                  maxValor = min( maxValor, subRect );
              }
            }
          }
        }
      }
    }
    printf("Case #%d: %d %d\n",cont++,maxArea,maxValor);
  }


  return 0;
}
