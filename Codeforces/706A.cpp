#include <iostream>
#include <cmath>

using namespace std;

double dist( double x, double y, double x1, double y1 )
{
  return sqrt( ( x1 - x )*( x1 - x ) + (y1 - y)*(y1 - y) );
}

int main()
{
  cout.precision( 10 );
  cout << fixed;
  double a,b,x,y,v;
  double min_time = 1e7;
  int n;
  cin >> a >> b >> n;
  for( int i = 0 ; i < n ; i++ )
  {
    cin >> x >> y >> v;
    min_time = min( min_time, dist( x,y,a,b ) / v );
  }
  cout << min_time << '\n';
  return 0;
}
