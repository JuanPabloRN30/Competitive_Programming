#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
#define INF 1e9

const double PI = acos(-1.0);

struct point
{
    double x;
    double y;
    point( double _x, double _y ) : x(_x), y(_y) {}

    point( )
    {
        x = y = 0.0;
    }
};

double DEG_to_RAD( double theta )
{
    return (theta * PI) / 180.0;
}

point rotate( point p, double theta )
{
    double rad = DEG_to_RAD( theta );
    return point( p.x * cos( rad ) - p.y * sin( rad ), p.x * sin( rad ) + p.y * cos( rad ) );
}

int main()
{
    double post_a,post_b,envelope_a,envelope_b;
    vector < point > post(5);
    scanf("%lf%lf%lf%lf",&post_a,&post_b,&envelope_a,&envelope_b);
    post[ 0 ] = point( 0.0, 0.0 );
    post[ 1 ] = point( post_a, 0.0 );
    post[ 2 ] = point( 0.0, post_b);
    post[ 3 ] = point( post_a, post_b );
    double angulo = 0.0;
    double max_x,max_y,min_x,min_y,difference_x,difference_y;
    bool can = false;
    vector < point > aux( post );
    while( angulo <= 360.0 && !can )
    {
        max_x = max_y = -INF;
        min_x = min_y = INF;
        for( int i = 0 ; i < 4 ; i++ )
            aux[ i ] = rotate( post[ i ], angulo );
        for( int i = 0 ; i < 4 ; i++ )
        {
                max_x = max( aux[ i ].x, max_x );
                max_y = max( aux[ i ].y, max_y );
                min_x = min( aux[ i ].x, min_x );
                min_y = min( aux[ i ].y, min_y );
        }
        difference_x = max_x - min_x;
        difference_y = max_y - min_y;
        if( difference_x <= envelope_a && difference_y <= envelope_b )
            can = true;
        angulo += 0.01;
    }
    angulo = 0.0;
    while( angulo <= 360.0 && !can )
    {
        max_x = max_y = -INF;
        min_x = min_y = INF;
        for( int i = 0 ; i < 4 ; i++ )
            aux[ i ] = rotate( post[ i ], angulo );
        for( int i = 0 ; i < 4 ; i++ )
        {
                max_x = max( aux[ i ].x, max_x );
                max_y = max( aux[ i ].y, max_y );
                min_x = min( aux[ i ].x, min_x );
                min_y = min( aux[ i ].y, min_y );
        }
        difference_x = max_x - min_x;
        difference_y = max_y - min_y;
        if( difference_x <= envelope_b && difference_y <= envelope_a )
            can = true;
        angulo += 0.01;
    }
    if( can )
        puts("Possible");
    else
        puts("Impossible");
    return 0;
}
