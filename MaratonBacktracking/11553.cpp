#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > matriz;
int menor;


void backtrack(int x, int y, int acum,int cont, vector < bool > fila, vector < bool > columna)
{
  if(cont == (int)matriz.size())
  {
    menor = min(menor,acum);
  }
  else
  {
    for(int i = 0 ; i < (int)matriz.size() ; i++)
    {
      if(!fila[ x ] && !columna[ i ])
      {
        fila[ x ] = true;
        columna[ i ] = true;
        backtrack(x+1,i,acum + matriz[ x ][ i ], cont + 1,fila,columna);
        fila[ x ] = false;
        columna[ i ] = false;
      }
    }
  }
}

int main()
{
  int t;
  scanf("%d",&t);
  while( t-- )
  {
    int n;
    scanf("%d",&n);
    matriz.assign(n, vector < int > (n,0));
    vector < bool > fila(n,false);
    vector < bool > columna(n,false);
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < n ; j++)
      {
        scanf("%d",&matriz[i][j]);
      }
    }
    menor = 10000;
    int acum = 0;
    int cont = 0;
    backtrack(0,0,acum,cont,fila,columna);
    printf("%d\n",menor);
  }
  return 0;
}
