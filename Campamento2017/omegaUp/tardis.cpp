#include <bits/stdc++.h>

using namespace std;

#define MAX 1000010

const int INF = 1e9 + 1;

struct Nodo
{
    int value;
    Nodo* left;
    Nodo* right;
};

Nodo* roots[ MAX ];
int sz;

struct st
{
    int tam;

    st( vector < int > &arr )
    {
        tam = arr.size();
        addRoot();
        build( 0, tam - 1, arr, roots[ sz - 1 ] );
    }

    void addRoot()
    {
        Nodo* head = new Nodo;
        roots[ sz ] = head ;
        sz++;
    }

    void build( int low, int high, vector < int > &arr, Nodo* pos)
    {
        if( low == high )
        {
            pos->value = arr[ low ];
            pos->left = NULL;
            pos->right = NULL;
            return;
        }
        int mid = ( high + low ) >> 1;
        pos->left = new Nodo;
        pos->right = new Nodo;
        build( low, mid, arr, pos->left );
        build( mid + 1, high, arr, pos->right );
        pos->value = max( pos->left->value, pos->right->value );
    }

    int query( int &qLow, int &qHigh, int low, int high, Nodo* pos)
    {
        if( qLow > high || qHigh < low )
            return -INF;
        if( low >= qLow && high <= qHigh )
            return pos->value;
        int mid = ( high + low ) >> 1;
        int res_i = query( qLow, qHigh, low, mid, pos->left);
        int res_d = query( qLow, qHigh, mid + 1, high, pos->right);
        return max( res_i, res_d );
    }

    int query( int &qLow, int &qHigh, int &current )
    {
        return query( qLow, qHigh, 0, tam-1, roots[ current ] );
    }

    void update( int &qPos, int &qValue, int low, int high, Nodo* pos, Nodo* nuevo )
    {
        if( qPos > high || qPos < low )
            return ;
        if( low == high && qPos == low )
        {
            nuevo->value = qValue;
            nuevo->left = NULL;
            nuevo->right = NULL;
            return;
        }
        int mid = ( high + low ) >> 1;
        if( qPos <= mid )
        {
            nuevo->right = pos->right;
            nuevo->left = new Nodo;
            update( qPos, qValue, low, mid, pos->left, nuevo->left );
        }
        else
        {
            nuevo->left = pos->left;
            nuevo->right = new Nodo;
            update( qPos, qValue, mid + 1, high, pos->right, nuevo->right );
        }
        nuevo->value = max( nuevo->left->value, nuevo->right->value );
    }

    void createState( int &val, int &current )
    {
        int aux = sz - val - 1;
        addRoot();
        roots[ sz - 1 ] = roots[ aux ];
    }

    void update( int &qPos, int &qValue, int &current )
    {
        addRoot();
        update( qPos, qValue, 0, tam - 1, roots[ current ], roots[ sz - 1 ] );
    }

};

int main()
{
    int n,q,op,low,value,high,current;
    scanf("%d%d",&n,&q);
    current = 0;
    sz = 0;
    vector < int > arr( n );
    for( int i = 0 ; i < n ; i++ )
        scanf("%d",&arr[ i ]);
    st tree( arr );

    for( int i = 0 ; i < q ; i++ )
    {
        scanf("%d",&op);
        if( op == 0 )
        {
            scanf("%d%d",&low,&high);
            printf("%d\n",tree.query( low, high, current ));
        }
        else if( op == 1 )
        {
            scanf("%d%d",&low,&value);
            tree.update( low, value, current );
            current = sz - 1;
        }
        else
        {
            scanf("%d",&value);
            tree.createState( value, current );
            current = sz - 1;
        }
    }
    return 0;
}
