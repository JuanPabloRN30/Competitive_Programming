#include <bits/stdc++.h>

using namespace std;

#define INF 1e9

long double area_triangulo( long double lado )
{
  long double lado_medios = lado * 0.5;
  return (lado * sqrt( (lado * lado) - ( lado_medios * lado_medios ) ) ) * 0.5;
}

int main()
{
  int t,n;
  char type;
  cin >> t;
  while( t-- )
  {
    cin >> n;
    long double base,altura,value;
    long double acum = 0.0;
    long double acum_area = 0.0;
    long double anterior;
    int cont = 0;
    for( int i = 0 ; i < n ; i++ )
    {
      cin >> type >> value;
      acum += value;
      if( type == 'C' )
      {
        cont++;
        if( cont == 2 )
        {
          base = acum;
          acum = 0.0;
          anterior = value;
        }
        if( cont == 3 )
        {
          altura = acum + anterior;
        }
        acum_area += value * value;
      }
      else
      {
        if( type == 'S' )
          acum_area += value * value;
        else
          acum_area += area_triangulo( value );
      }

    }
    acum = base * altura;
    // cout << base << " " << altura << endl;
    // cout << acum_area << endl;
    cout << fixed << setprecision(4) << acum - acum_area << endl;
  }

  return 0;
}
