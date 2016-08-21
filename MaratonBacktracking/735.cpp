#include <bits/stdc++.h>

using namespace std;

int permutations;
int combinations;

void ya_esta_combinado(vector < pair < int , pair < int , int > > > &datos, int x, int y, int z)
{
  bool combinado = false;
  permutations++;
  for(int i = 0 ; i < (int)datos.size() ; i++)
  {
    if(datos[i].first == x && datos[i].second.first == y && datos[i].second.second == z)
    combinado = true;
    else if(datos[i].first == x && datos[i].second.first == z && datos[i].second.second == y)
    combinado = true;
    else if(datos[i].first == y && datos[i].second.first == x && datos[i].second.second == z)
    combinado = true;
    else if(datos[i].first == y && datos[i].second.first == z && datos[i].second.second == x)
    combinado = true;
    else if(datos[i].first == z && datos[i].second.first == x && datos[i].second.second == y)
    combinado = true;
    else if(datos[i].first == z && datos[i].second.first == y && datos[i].second.second == x)
    combinado = true;
  }
  if(!combinado)
  {
    combinations++;
    //cout << x << " " << y << " " << z << endl;
  }
  datos.push_back(make_pair(x,make_pair(y,z)));
}

int main()
{
  int numero;
  vector < bool > numeros(61,false);
  numeros[ 0 ] = true;
  numeros[ 1 ] = true;
  for(int i = 2 ; i <= 20 ; i++)
  {
    for(int j = 1 ; j<= 3 ; j++)
    {
      numeros[ i*j ] = true;
    }
  }
  vector < int > numeros_reales;
  for(int i = 0 ; i < numeros.size() ; i++)
  {
    if(numeros[i])
    {
      numeros_reales.push_back(i);
    }
  }
  numeros_reales.push_back(50);
  while(scanf("%d",&numero) && numero > 0)
  {
    permutations = 0;
    combinations = 0;
    vector < pair < int , pair < int , int > > > datos;
    for(int i = 0 ; i < (int)numeros_reales.size() ; i++)
    {
      for(int j = 0 ; j < (int)numeros_reales.size() ; j++)
      {
        for(int k = 0 ; k < (int)numeros_reales.size() ; k++)
        {
          if(numeros_reales[i]+numeros_reales[j]+numeros_reales[k] == numero )
          {
            ya_esta_combinado(datos,numeros_reales[i],numeros_reales[j],numeros_reales[k]);
          }
        }
      }
    }
  if(combinations == 0 && permutations == 0)
  {
    printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",numero);
    printf("**********************************************************************\n");
    continue;
  }
  printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",numero,combinations);
  printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n",numero,permutations );
  printf("**********************************************************************\n");
}
printf("END OF OUTPUT\n");

return 0;
}
