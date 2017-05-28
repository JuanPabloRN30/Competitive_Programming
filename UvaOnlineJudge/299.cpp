#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  scanf("%d",&n);
  while( n-- )
  {
    int l;
    scanf("%d",&l);
    int arreglo[ 60 ];
    for(int i = 0 ; i < l ; i++)
      scanf("%d",&arreglo[ i ] );
    bool noflip = true;
    int cont = 0;
    do{
      noflip = false;
      for(int i = 0 ; i < l-1 ; i++)
      {
        // cout << arreglo[ i ] << " " << arreglo[ i+1  ] << endl;
        if( arreglo[ i ] > arreglo[ i+1 ] )
        {
          swap( arreglo[ i ], arreglo[ i+1 ] );
          noflip = true;
          cont++;
        }
      }

    }while( noflip );
    printf("Optimal train swapping takes %d swaps.\n",cont);
  }
  return 0;
}
