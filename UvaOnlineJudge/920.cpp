#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9

struct point
{
    double x,y;
    point() {  x = y = 0.0;}
    point( double _x , double _y ) : x(_x),y(_y){}

    bool operator < ( point other ) const
    {
        if( fabs( x - other.x ) > EPS )
            return x < other.x;
        return y < other.y;
    }

};

double dist( point p1, point p2 )
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt( dx * dx + dy * dy );
}

int main()
{
    int cases,n;
    scanf("%d",&cases);
    while( cases-- )
    {
        scanf("%d",&n);
        vector < point > points( n );
        double acum = 0.0;
        double total = 0.0,pendiente;
        for( int i = 0 ; i < n ; i++ )
        {
            scanf("%lf%lf",&points[ i ].x,&points[ i ].y);
        }
        sort(points.begin(), points.end());
        int index = n-1;
        for( int i = n-2 ; i >= 0 ; i-- )
        {
            if( points[ i ].y > points[ index ].y )
            {
                point p_new;
                if( index == i+1  )
                    total = dist( points[ i ], points[ i+1 ] );
                else
                {
                    pendiente = (points[ i+1 ].y - points[ i ].y) / (points[ i + 1 ].x - points[ i ].x);
                    p_new.y = points[ index ].y;
                    p_new.x = ((points[ index ].y - points[ i + 1 ].y)/pendiente) + points[ i + 1 ].x;
                    total = dist( points[ i ], p_new );
                }
                acum += total;
                index = i;
            }
        }
        printf("%.2f\n",acum);
    }

    return 0;
}
