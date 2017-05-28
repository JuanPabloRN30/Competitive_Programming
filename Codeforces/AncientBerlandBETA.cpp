#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define PI acos(-1.0)

struct point
{
  double x,y;

  point(){ x = y = 0.0;}
  point(double _x, double _y) : x(_x),y(_y){}
};

double hypot( double dx, double dy )
{
  return sqrt( dx * dx + dy * dy );
}

double dist( point p1, point p2 )
{
  return hypot( p1.x - p2.x, p1.y - p2.y );
}

double area( double ab, double ac, double bc )
{
  double semi = (ab + ac + bc) * 0.5;
  return sqrt( semi * ( semi - ab) * ( semi - ac ) * ( semi - bc ) );
}

double getRadio( double ab, double ac, double bc )
{
  return ( ab * ac * bc) / ( 4.0 * area(ab, ac, bc) );
}

double areaPolygon( double radius, double n )
{
  return (n * radius * radius * sin( (2 * PI) / n )) * 0.5;
}

double getAngle( double ab, double ac, double bc )
{
  return acos( ( ac*ac + bc*bc - ab * ab ) / ( 2 * ac* bc ) );
}

double gcd(double x, double y) {
    while (fabs(x) > EPS && fabs(y) > EPS) {
        if (x > y)
                x -= floor(x / y) * y;
        else
                y -= floor(y / x) * x;
    }
    return x + y;
}

int main()
{
  point a,b,c;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  cin >> c.x >> c.y;
  double ab,ac,bc;
  ab = dist( a,b );
  ac = dist( a,c );
  bc = dist( b,c );
  double radio = getRadio( ab, ac ,bc );
  double A = getAngle( ab, ac ,bc );
  double B = getAngle( ac, ac ,bc );
  double C = getAngle( bc, ab ,ac );
  double n = PI / gcd( gcd( A,B ), C );
  cout << fixed << setprecision(8) << areaPolygon( radio, n ) << endl;
  return 0;
}
