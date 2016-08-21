#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  while( scanf("%d",&n) && n )
  {
    long long acumulador = 0;
    long long maximo = 0;
    int valor;
    for(int i = 0 ; i < n ; i++)
    {
      scanf("%d",&valor);
      acumulador = valor + acumulador;
      if(acumulador < 0)
        acumulador = 0;
      maximo = max(maximo,acumulador);
    }
    if( maximo )
      printf("The maximum winning streak is %lld.\n",maximo);
    else
      printf("Losing streak.\n");
  }


  return 0;
}
