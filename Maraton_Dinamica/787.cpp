#include <bits/stdc++.h>

using namespace std;

int main()
{


  long long numero;
  string linea;
  while( getline(cin,linea) )
  {
    vector < __int128 > arreglo;
    stringstream ss(linea);
    while(ss >> numero)
    {
      if(numero != -999999)
        arreglo.push_back( numero );
    }
    __int128 maximo = -999999;
    for(int i = 0 ; i < (int)arreglo.size() ; i++)
    {
      __int128 acumulador = 1;
      for(int j = i ; j < (int)arreglo.size() ; j++)
      {
        acumulador = arreglo[ j ] * acumulador;
        maximo = max(maximo, acumulador);
      }
    }
    if( maximo != -999999 )
      printf("%lld\n",(long long )maximo);
  }


  return 0;
}
