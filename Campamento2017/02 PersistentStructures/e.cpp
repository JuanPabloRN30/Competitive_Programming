#include <bits/stdc++.h>

using namespace std;

#define MAX 200010

struct Node
{
    int value;
    Node* left;
    Node* right;

    Node()
    {
        value = 0;
        left = right = NULL;
    }

    Node( Node* o )
    {
        value = o->value;
        left = o->left;
        right = o->right;
    }

    Node( int val )
    {
        value = val;
        left = right = NULL;
    }
};

struct st
{
    int tam;

    st( vector < int > &arr, Node* &root )
    {
        tam = arr.size();
        root = build( 0, tam );
    }

    Node* build(int low, int high)
    {
        if( low == high )
            return new Node;
        int mid = ( low + high ) >> 1;
        Node* pos = new Node;
        pos->left = build( low, mid);
        pos->right = build( mid + 1, high);
        return pos;
    }

    int query( int k ,int low, int high, Node* pos)
    {
        if( low == high && pos->value-k == 0 )
            return low;
        else if( low == high)
            return -1;
        int izq = pos->left->value;
        int der = pos->right->value;
        int mid = ( low + high ) >> 1;
        if( k <= izq )
            return query( k, low, mid, pos->left );
        else
            return query( k - izq , mid + 1, high, pos->right );
    }

    int query( int k, Node* pos )
    {
        return query( k, 0 , tam - 1, pos );
    }

    Node* update( int &qPos, int &qValue, int low, int high, Node* pos)
    {
        if( high == low && low == qPos)
            return new Node( qValue );
        Node* nuevo = new Node( pos );
        int mid = ( low + high ) >> 1;
        if( qPos <= mid  )
            nuevo->left = update( qPos, qValue, low, mid, pos->left);
        else
            nuevo->right = update( qPos, qValue, mid + 1, high , pos->right);
        nuevo->value = nuevo->left->value + nuevo->right->value;
        return nuevo;
    }

    Node* update( int &qPos, int qValue, Node* pos)
    {
        return update( qPos, qValue, 0, tam - 1, pos);
    }
};

int main()
{
    int n,m,p,q,x,y,l,k;
    scanf("%d%d",&n,&m);
    vector <int > arr(n);
    for( int i = 0 ; i < n; ++i )
    {
        scanf("%d",&arr[ i ]);
    }
    vector < int > aux( n, 0 );
    vector < int > identifiers( MAX, -1);
    Node* roots[ MAX ];
    st tree( aux, roots[ n + 1 ] );
    int version = n + 1;
    for( int i = n - 1 ; i >= 0 ; --i )
    {
        version--;
        if( identifiers[ arr[ i ] ] == -1 )
        {
            identifiers[ arr[ i ] ] = i;
            roots[ version ] = tree.update( i, 1, roots[ version + 1 ]);
        }
        else
        {
            roots[ version ] = tree.update( identifiers[ arr[ i ] ], 0, roots[ version + 1 ]);
            identifiers[ arr[ i ] ] = i;
            roots[ version ] = tree.update( i, 1, roots[ version ]);
        }
    }
    scanf("%d",&q);
    p = 0;
    while( q-- )
    {
        scanf("%d%d",&x,&y);
        l = (( x + p )%n) + 1;
        k = (( y + p)%m)+1;
        p = tree.query( k, roots[ l ] ) + 1;
        printf("%d\n",p);

    }
    return 0;
}
