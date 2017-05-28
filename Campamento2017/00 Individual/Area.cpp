#include <bits/stdc++.h>

using namespace std;

struct point
{
    double x;
    double y;
    point( double _x, double _y ) : x(_x), y(_y){}
    point(){
        x = y = 0;
    }
};

double area( vector < point > &points )
{
    double sum = 0.0;
    for( int i = 0 ; i < points.size()-1 ; i++ )
    {
        double dx = points[ i ].x * points[ i + 1 ].y;
        double dy = points[ i ].y * points[ i + 1 ].x;
        sum += ( dx-dy );
    }
    return fabs(sum / 2.0);
}

int main()
{
    int n;
    scanf("%d",&n);
    vector < point > points(n+1);
    for( int i = 0 ; i < n ; i++ )
    {
        scanf("%lf%lf",&points[ i ].x,&points[ i ].y);
    }
    points[ n ] = points[ 0 ];
    double result = area( points );
    printf("%.3lf\n",result);
    return 0;
}
