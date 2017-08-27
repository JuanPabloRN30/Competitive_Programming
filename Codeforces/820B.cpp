#include <iostream>
#include <cmath>

using namespace std;

int main()
{
  int n,a,ans;
  double angulo_vertice, minimo_angulo = 1e7;
  cin >> n >> a;
  angulo_vertice = ((n - 2) * 180.0) / n;

  cout << "2 1 ";
  for( int i = 1 ; i <= n - 2 ; i++ )
  {
    double angulo_actual = (angulo_vertice * i) / (n-2);
    if( fabs(angulo_actual - a) < minimo_angulo )
    {
      minimo_angulo = fabs( angulo_actual - a );
      ans = i;
    }
  }
  cout << ans + 2 << '\n';
  return 0;
}
