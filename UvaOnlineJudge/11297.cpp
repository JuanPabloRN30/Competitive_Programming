#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;
const int INF = 1e9;

struct SegmentTree
{
    vector < ii > tree;
    int tam;

    SegmentTree( int arr[][510], int n )
    {
        tam = n;
        tree.resize( 1e8 );
        build( 0, 0, n-1, n-1, 0, arr );
    }

    ii build(int i, int j, int x, int y, int pos, int arr[][ 510 ])
    {
        if( i > x || j > y )
            return ii(INF, -INF);
        if( i == x && j == y )
            return tree[ pos ] = ii(arr[ i ][ j ], arr[ i ][ j ]);
        int total = ( abs(i - x) + 1 ) * ( abs(j - y) + 1 );
        int midF = ( i + x ) >> 1;
        int midC = ( y + j ) >> 1;
        int first = (pos << 2) | 1;
        int second = first + 1;
        int third = second + 1;
        int fourth = third + 1;
        ii _first = build( i, j, midF, midC, first, arr );
        ii _second = build( i, midC + 1, midF, y, second, arr );
        ii _third = build( midF + 1, j, x, midC, third, arr );
        ii _fourth = build( midF + 1, midC + 1, x, y, fourth, arr );
        return tree[ pos ] = ii( min( _first.first, min( _second.first, min( _third.first, _fourth.first ) ) ), max( _first.second, max( _second.second, max( _third.second, _fourth.second ) ) ) );
    }

    ii query( int i, int j, int x, int y, int pos, int &f1Q, int &c1Q, int &f2Q, int &c2Q )
    {
        if( i > x || j > y )
            return ii(INF, -INF);
        if( i >= f1Q && j >= c1Q && x <= f2Q && y <= c2Q )
            return tree[ pos ];
        else if( c2Q < j || c1Q > y || f2Q < i || f1Q > x )
            return ii( INF, -INF );
        else
        {
            int total = ( abs(i - x) + 1 ) * ( abs(j - y) + 1 );
            int midF = ( i + x ) >> 1;
            int midC = ( y + j ) >> 1;
            int first = (pos << 2) | 1;
            int second = first + 1;
            int third = second + 1;
            int fourth = third + 1;
            ii _first = query( i, j, midF, midC, first, f1Q, c1Q, f2Q, c2Q);
            ii _second = query( i, midC + 1, midF, y, second, f1Q, c1Q, f2Q, c2Q );
            ii _third = query( midF + 1, j, x, midC, third, f1Q, c1Q, f2Q, c2Q );
            ii _fourth = query( midF + 1, midC + 1, x, y, fourth, f1Q, c1Q, f2Q, c2Q );
            return ii( min( _first.first, min( _second.first, min( _third.first, _fourth.first ) ) ), max( _first.second, max( _second.second, max( _third.second, _fourth.second ) ) ) );
        }
    }

    ii update(int i, int j, int x, int y, int pos, int &fQ, int &cQ, int &value)
    {
        if( i > x || j > y )
            return ii(INF, -INF);
        if( cQ < j || cQ > y || fQ < i || fQ > x )
            return tree[ pos ];
        else if( i == fQ && j == cQ && i == x && j == y )
            return tree[ pos ] = ii( value,value );
        else
        {
            int total = ( abs(i - x) + 1 ) * ( abs(j - y) + 1 );
            int midF = ( i + x ) >> 1;
            int midC = ( y + j ) >> 1;
            int first = (pos << 2) | 1;
            int second = first + 1;
            int third = second + 1;
            int fourth = third + 1;
            ii _first = update( i, j, midF, midC, first, fQ, cQ, value);
            ii _second = update( i, midC + 1, midF, y, second, fQ, cQ, value);
            ii _third = update( midF + 1, j, x, midC, third, fQ, cQ, value);
            ii _fourth = update( midF + 1, midC + 1, x, y, fourth, fQ, cQ, value);
            return tree[ pos ] = ii( min( _first.first, min( _second.first, min( _third.first, _fourth.first ) ) ), max( _first.second, max( _second.second, max( _third.second, _fourth.second ) ) ) );
        }
    }

    ii query( int i , int j, int x, int y )
    {
        return query( 0, 0 , tam - 1, tam - 1, 0 , i , j, x, y );
    }

    void print()
    {
        cout << tree[ 0 ].second << " " << tree[ 0 ].first << endl;
        /*for( int i = 0 ; i < tree.size() ; i++ )
            cout << tree[ i ].first << " " << tree[ i ].second << endl;
        cout << endl;*/
    }
};

int main()
{
    int n,query,f1,f2,c1,c2,val;
    char opc;
    ii result;
    scanf("%d",&n);
    int arr[ n ][ 510 ];
    for( int i = 0 ; i < n ; ++i )
        for( int j = 0 ; j < n ; ++j )
            scanf("%d",&arr[ i ][ j ]);
    SegmentTree st( arr, n );
    scanf("%d",&query);
    for( int i = 0 ; i < query ; ++i )
    {
        cin >> opc;
        if( opc == 'q' )
        {
            scanf("%d%d%d%d",&f1,&c1,&f2,&c2);
            result = st.query( f1 - 1, c1 - 1, f2 - 1, c2 - 1 );
            printf("%d %d\n",result.second,result.first);
        }
        else
        {
            scanf("%d%d%d",&f1,&c1,&val);
            f1--;
            c1--;
            st.update( 0,0,n-1,n-1,0,f1,c1,val );
            //st.print();
        }
    }
    return 0;
}
