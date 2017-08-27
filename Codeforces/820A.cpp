#include <iostream>

using namespace std;

int main()
{
  int c,v0,v1,a,l;
  cin >> c >> v0 >> v1 >> a >> l;
  int acum = v0;
  int cont = 1;
  int incremento = 0;
  while( acum < c )
  {
    if( v0+incremento+a <= v1 )
    {
      incremento += a;
      acum = acum + (v0 + incremento);
    }
    else
      acum = acum + v1;
    acum -= l;
    ++cont;
  }
  cout << cont << '\n';

  return 0;
}
