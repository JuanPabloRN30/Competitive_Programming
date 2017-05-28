#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 1<<33;

struct st
{
    vector < ll > tree;
    int tam;

    st( int n )
    {
        tam = n;
        tree.resize( tam << 2 );
        build( 0, tam - 1, 0);
    }

    ll build( int low, int high, int pos)
    {
        if( low == high )
            return tree[ pos ] = INF;
        int mid = ( high + low ) >> 1;
        int izq = ( pos << 1 ) | 1;
        int der = izq + 1;
        return tree[ pos ] = min( build( low, mid, izq), build( mid + 1, high, der) );
    }

    int rmq( int &qLow, int &qHigh, int low, int high, int pos )
    {
        if( qLow > high || qHigh < low )
            return INF;
        if( low >= qLow && high <= qHigh )
            return tree[ pos ];
        int mid = ( high + low ) >> 1;
        int izq = ( pos << 1 ) | 1;
        int der = izq + 1;
        return min( rmq( qLow, qHigh, low, mid, izq ), rmq( qLow, qHigh, mid + 1, high, der ) );
    }

    int rmq( int &qLow, int &qHigh )
    {
        return rmq( qLow, qHigh, 0 , tam - 1, 0 );
    }

    ll update( int &qPos, int &qValue, int low, int high, int pos )
    {
        if( qPos > high || qPos < low )
            return INF;
        if( qPos == low && qPos == high )
            return tree[ pos ] = qValue;
        int mid = ( high + low ) >> 1;
        int izq = ( pos << 1 ) | 1;
        int der = izq + 1;
        return tree[ pos ] = min( update( qPos, qValue, low, mid, izq), update( qPos, qValue, mid + 1, high, der) );
    }
};

int main()
{
    int n,m,i,j;
    ll q;
    scanf("%d%d",&n,&m);
    st tree( n );
    for( int ii = 0 ; ii < m ; ii++)
    {
        scanf("%d%d%lld",&i,&j,&q);
        tree.update( i, j, q );
    }
    return 0;
}
