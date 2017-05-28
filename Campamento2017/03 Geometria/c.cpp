#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-6

const float PI = acos(-1.0);

float perimeter;

struct point
{
    float x,y;

    point(float _x , float _y)
    {
        x = _x;
        y = _y;
    }

    point()
    {
        x = y = 0;
    }
};

float dist(point &a , point &b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return sqrt(dx *dx + dy * dy);
}

struct vec
{
    float x,y;

    vec(float _x , float _y)
    {
        x = _x;
        y = _y;
    }
};

vec toVector(point a , point b)
{
    return vec(b.x - a.x , b.y - a.y);
}

float dot(vec a , vec b)
{
    return a.x*b.x + a.y*b.y;
}

float norm_sq(vec v)
{
    return v.x*v.x + v.y*v.y;
}

float angle(point &a , point &o , point &b)
{
    vec oa = toVector(o , a) , ob = toVector(o , b);
    return acos(dot(oa , ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

bool intersection( point from, point to, point center, float radius )
{
    float t1,t2;
    vec d( toVector(from, to) );
    vec f( toVector(center, from) );
    float a = dot( d, d );
    float b = 2 * dot( f,d );
    float c = dot( f, f ) - radius * radius;
    float discriminante = b * b - 4 * a * c;
    bool can, can1;
    can = can1 = false;
    if( discriminante > EPS )
    {
        discriminante = sqrt( discriminante );
        t1 = ( -b - discriminante ) / (  2.0 * a );
        t2 = ( -b + discriminante ) / (  2.0 * a );
        if( t1 >= EPS && t1 <= 1.0 )
            can = true;
        if( t2 >= EPS && t2 <= 1.0 )
            can1 = true;
    }
    return can && can1;
}

point rotate( point p, float rad )
{
    //float rad = (theta * PI  / 180.0);
    return point( p.x * cos( rad ) - p.y * sin( rad ), p.x * sin( rad ) + p.y * cos( rad ) );
}

float arc( float theta )
{
    return (theta / 360.0) * perimeter;
}

int main()
{
    point from, center,to;
    float radius;
    cin >> from.x  >> from.y >> to.x >> to.y;
    cin >> center.x >> center.y >> radius;

    perimeter = 2.0 * PI * radius;

    // FROM TO CENTER
    vec fc = toVector( from, center );
    float ang = asin( radius / dist( center, from ) );
    point ct_1 = rotate( point( fc.x, fc.y) , ang );
    point ct_2 = rotate( point( fc.x, fc.y), -ang );

    // DESTINY TO CENTER
    vec tc = toVector( center, to );
    ang = asin( radius / dist( center, to ) );
    point ct_3 = rotate( point( tc.x, tc.y) , ang );
    point ct_4 = rotate( point( tc.x, tc.y), -ang );

    float value1 = dist( from, to );
    float value2 = dist( from, ct_1 ) + arc( angle( ct_1, center, ct_3 ) ) + dist( to, ct_3 ) ;
    float value3 = dist( from, ct_2 ) + arc( angle( ct_2, center, ct_4 ) ) + dist( to, ct_4 ) ;

    if( intersection( from, to, center, radius ) )
        cout << fixed << setprecision(6) << min( value2, value3 ) << endl;
    else
        cout << fixed << setprecision(6) << value1 << endl;

    return 0;
}
