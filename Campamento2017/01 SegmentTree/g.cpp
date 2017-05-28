#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

struct SegmentTree
{
    vector < int > tree;
    int tam;

    SegmentTree( int arr[], int n )
    {
        tam = n;
        tree.resize( n << 2 );
        build( 0, n - 1, 0, arr );
    }

    ll build(int i, int j, int pos, int arr[])
    {
        if( i == j )
        {
            if( arr[ i ] > 0 )
                return tree[ pos ] = 1;
            else if( arr[ i ] < 0 )
                return tree[ pos ] = -1;
            else
                return tree[ pos ] = 0;
        }
        int mid = ( i + j ) >> 1;
        int left = (pos << 1) | 1;
        int right = left + 1;
        int result_left = build( i, mid, left, arr );
        int result_right = build( mid + 1, j, right, arr );
        if( result_left == 0 || result_right == 0 )
            return tree[ pos ] = 0;
        else if( result_left > 0 && result_right > 0 || result_left < 0 && result_right < 0 )
            return tree[ pos ] = 1;
        else
            return tree[ pos ] = -1;
    }

    ll query( int i, int j, int pos, int &inf, int &sup )
    {
        if( i >= inf && j <= sup )
            return tree[ pos ];
        else if( j < inf || i > sup )
            return 1;
        else
        {
            int mid = ( i + j ) >> 1;
            int left = (pos << 1) | 1;
            int right = left + 1;
            int result_left = query( i, mid, left, inf, sup );
            int result_right = query( mid + 1, j, right, inf, sup );
            if( result_left == 0 || result_right == 0 )
                return 0;
            else if( result_left > 0 && result_right > 0 || result_left < 0 && result_right < 0 )
                return 1;
            else
                return -1;
        }
    }

    ll query( int i , int j )
    {
        return query( 0, tam - 1 , 0 , i , j );
    }

    ll update( int i, int j, int pos, int &newValue, int &posChange )
    {
        if( j < posChange || i > posChange )
            return tree[ pos ];
        else if( i == posChange && j == posChange )
        {
            if( newValue > 0 )
                return tree[ pos ] = 1;
            else if( newValue < 0 )
                return tree[ pos ] = -1;
            else
                return tree[ pos ] = 0;
        }
        else
        {
            int mid = ( i + j ) >> 1;
            int left = (pos << 1) | 1;
            int right = left + 1;
            int result_left = update( i, mid, left, newValue, posChange );
            int result_right =update( mid + 1, j, right, newValue, posChange );
            if( result_left == 0 || result_right == 0 )
                return tree[ pos ] = 0;
            else if( result_left > 0 && result_right > 0 || result_left < 0 && result_right < 0 )
                return tree[ pos ] = 1;
            else
                return tree[ pos ] = -1;
        }
    }

    void print()
    {
        for( int i = 0 ; i < tree.size() ; i++ )
            cout << tree[ i ] << " ";
        cout << endl;
    }
};


int main()
{
    ordered_set X;


    return 0;
}
