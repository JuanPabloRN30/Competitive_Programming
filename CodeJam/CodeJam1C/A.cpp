#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  scanf("%d",&t);
  for(int i = 0 ; i < t ; i++)
  {
    printf("Case #%d: ",i+1);
    int n;
    scanf("%d",&n);
    vector < pair < char,int> > arreglo(n);
    int numero;
    int suma = 0;
    for(int i = 0 ; i < n ; i++)
    {
      scanf("%d",&numero);
      char caracter = 'A'+i;
      arreglo[i].first = caracter;
      arreglo[i].second = numero;
      suma += numero;
    }
    sort(arreglo.rbegin(),arreglo.rend());
    int salida = 0;
    int suma2 = suma;
    while(salida != suma2)
    {
      for(int i = 0 ; i < n ; i++)
      {
        if(arreglo[i].second > suma/2)
        {
          int aux = arreglo[i].second-(suma/2);
          arreglo[i].second -= aux;
          for(int j = 0 ; j < aux ; j++)
            printf("%c",arreglo[i].first);
          salida += aux;
          suma -= aux;
        }
        else
        {
          int aux = arreglo[i].second;
          arreglo[i].second -= aux;
          for(int j = 0 ; j < aux ; j++)
            printf("%c",arreglo[i].first);
          salida += aux;
          suma -= aux;
        }
        printf(" ");
      }
    }
    printf("\n");
  }

  return 0;
}
