#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int Y;
  while(scanf("%d",&Y) != EOF)
  {
    int P;
    scanf("%d",&P);
    vector < int > years(P,0);
    for(int i = 0 ; i < P ; i++)
    {
      scanf("%d",&years[i]);
    }
    int mayor = 0;
    int cont = 0;
    int pos_final;
    int pos_inicial;
    for(int i = 0 ; i < P ; i++)
    {
      if(cont == 0)
      {
        pos_inicial = i;
      }
      int j = i;
      while( years[ j ] < years[ pos_inicial ]+Y  && j < P)
      {
        cont++;
        j++;
      }
      if(cont > mayor)
      {
        mayor = cont;
        pos_final = j;
      }
      cont = 0;
    }
    printf("%d %d %d\n",mayor,years[ pos_final-mayor ],years[ pos_final-1 ] );
  }

  return 0;
}
