#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

struct SegmentTree
{
    vector < ii > tree;
    int tam;

    SegmentTree( int arr[], int n )
    {
        tam = n;
        tree.resize( n << 2 );
        build( 0, n - 1, 0, arr );
    }

    ii build(int i, int j, int pos, int arr[])
    {
        if( i == j )
            return tree[ pos ] = ii( arr[ i ], arr[ i ] );
        int mid = ( i + j ) >> 1;
        int left = (pos << 1) | 1;
        int right = left + 1;
        ii _izq = build( i, mid, left, arr );
        ii _der = build( mid + 1, j, right, arr );
        vector < int > aux;
        aux.push_back( _izq.first );
        aux.push_back( _izq.second );
        aux.push_back( _der.first );
        aux.push_back( _der.second );
        sort( aux.rbegin(), aux.rend() );
        cout << aux[ 0 ] << " " << aux[ 1 ] << endl;
        return tree[ pos ] = ii( aux[ 0 ], aux[ 1 ] );
    }

    ii query( int i, int j, int pos, int &inf, int &sup )
    {
        if( i >= inf && j <= sup )
            return tree[ pos ];
        else if( j < inf || i > sup )
            return ii(0,0);
        else
        {
            int mid = ( i + j ) >> 1;
            int left = (pos << 1) | 1;
            int right = left + 1;
            ii _izq = query( i, mid, left, inf, sup );
            ii _der = query( mid + 1, j, right, inf, sup );
            vector < int > aux;
            aux.push_back( _izq.first );
            aux.push_back( _izq.second );
            aux.push_back( _der.first );
            aux.push_back( _der.second );
            sort( aux.rbegin(), aux.rend() );
            return ii( aux[ 0 ], aux[ 1 ] );
        }
    }

    ii query( int i , int j )
    {
        return query( 0, tam - 1 , 0 , i , j );
    }

    ii update( int i, int j, int pos, int &posChange, int &value )
    {
        if( i == j && i == posChange )
            return tree[ i ] = ii( value, value );
        else if( j < posChange || i > posChange )
            return ii(0,0);
        else
        {
            int mid = ( i + j ) >> 1;
            int left = (pos << 1) | 1;
            int right = left + 1;
            ii _izq = update( i, mid, left, posChange, value );
            ii _der = update( mid + 1, j, right, posChange, value );
            vector < int > aux;
            aux.push_back( _izq.first );
            aux.push_back( _izq.second );
            aux.push_back( _der.first );
            aux.push_back( _der.second );
            sort( aux.rbegin(), aux.rend() );
            return tree[ pos ] = ii( aux[ 0 ], aux[ 1 ] );
        }
    }
};

int main()
{
    int n,value,q,value2;
    ii result;
    char opc;
    scanf("%d",&n);
    int arr[ n ];
    for( int i = 0 ; i < n ; i++ )
        scanf("%d",&arr[ i ]);
    SegmentTree st( arr, n );
    scanf("%d",&q);
    while( q-- )
    {
        cin >> opc;
        scanf("%d%d",&value,&value2);
            value--;
            value2--;
        if( opc == 'Q' )
        {
            result = st.query( value, value2 );
            printf("%d\n", result.first + result.second );
        }
        else
        {
            st.update( 0, n-1, 0, value, value2 );
        }
    }

    return 0;
}
