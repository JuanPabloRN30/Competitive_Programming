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

struct Head
{
    Node* root;
    int low;
    int high;
    Head()
    {
        root = NULL;
    }
};

Head roots[ MAX ];

struct st
{

    st( )
    {
        roots[ 0 ].root = build();
        roots[ 0 ].low = 0;
        roots[ 0 ].high = -1;
    }

    Node* build(int low = 0, int high = MAX - 1)
    {
        if( low == high )
            return new Node;
        int mid = ( low + high ) >> 1;
        Node* pos = new Node;
        pos->left = build( low, mid);
        pos->right = build( mid + 1, high);
        return pos;
    }

    int query( int &qPos, int low, int high, Node* pos)
    {
        if( high == low && low == qPos )
            return pos->value;
        int mid = ( low + high ) >> 1;
        if( qPos <= mid )
            return query( qPos, low, mid, pos->left);
        else
            return query( qPos, mid + 1, high, pos->right);
    }

    int query( int current )
    {
        return query( roots[ current ].low , 0, MAX - 1, roots[ current ].root);
    }

    Node* insertST( int qPos, int &value, int low, int high, Node* pos)
    {
        if( high == low && low == qPos )
            return new Node( value );
        Node* nuevo = new Node( pos );
        int mid = ( low + high ) >> 1;
        if( qPos <= mid )
            nuevo->left = insertST( qPos, value, low, mid, pos->left);
        else
            nuevo->right = insertST( qPos, value, mid + 1, high, pos->right);
        return nuevo;
    }

    Node* insertST( int &pos, int &value, Node* root)
    {
        return insertST( pos , value, 0, MAX - 1, root);
    }
};

int main()
{
    int n,op,version,value;
    scanf("%d",&n);
    st tree;
    for( int i = 1 ; i <= n ; i++ )
    {
        scanf("%d",&op);
        if( op == 1 )
        {
            scanf("%d%d",&version,&value);
            roots[ i ] = roots[ version ];
            roots[ i ].high++;
            roots[ i ].root = tree.insertST(roots[ i ].high, value, roots[ version ].root);
        }
        else
        {
            scanf("%d",&version);
            cout << tree.query( version ) << endl;
            roots[ i ] = roots[ version ];
            roots[ i ].low++;
        }
    }
    return 0;
}
