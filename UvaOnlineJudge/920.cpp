#include <bits/stdc++.h>

using namespace std;

struct TPoint
{
    double x,y;
    TPoint()
    {
        x = y = 0.0;
    }
    TPoint(double _x, double _y) : x(_x), y(_y){}

    bool operator< (const TPoint p) const
    {
        if( x < p.x )
            return x < p.x;
        return y < p.y;
    }

    TPoint operator- (const TPoint p) const
    {
        return TPoint( p.x - x , p.y - y );
    }

    double operator* (const TPoint p) const
    {
        return x * p.x + y * p.y;
    }

    TPoint operator* (const double p) const
    {
        return TPoint(x * p, y * p);
    }

    double operator~ () const
    {
        return x * x + y * y;
    }
};

TPoint points[110];

double dist_segment( TPoint )

int main()
{
    int c,n;
    cin >> c;
    while( c-- )
    {
        cin >> n;
        for( int i = 0 ; i < n ; i++ )
            cin >> points[i].x >> points[i].y;
        sort(points, points + n);
        double max_y = 0;
        double acum = ~(points[n-1]-points[n-2]);
        TPoint prev = points[n-2];
        for( int i = n-3 ; i >= 0 ; i-- )
        {
            if( points[i].y > max_y )
            {
                max_y = points[i].y;
                acum +=
            }
        }
    }
    return 0;
}
