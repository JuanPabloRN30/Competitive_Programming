#include <iostream>
#include <cmath>

using namespace std;

#define EPS 1e-6

int main()
{
  cout.precision(10);
  cout << fixed;
  int d,h,v,e;
  cin >> d >> h >> v >> e;
  double radio = d*0.5;
  double salida = v / ( acos(-1.0)*radio*radio );
  if( e - salida < EPS )
  {
    puts("YES");
    cout << fabs(h / ( e - salida )) << '\n';
  }
  else
    puts("NO");
  return 0;
}
