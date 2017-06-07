#include <bits/stdc++.h>

using namespace std;

#define MAX 100000

struct Node
{
  Node *left,*right;
  int val;
  Node()
  {
    this->val = 0;
    this->left = this->right = NULL;
  }
  Node( Node *other )
  {
    this->val = other->val;
    this->left = other->left;
    this->right = other->right;
  }
  Node( int value )
  {
    this->val = value;
    this->left = this->right = NULL;
  }
};

struct SegmentTree
{
  int tam;

  SegmentTree( int data[], int n, Node* &root )
  {
    this->tam = n;
    root = build( 0, n );
  }

  Node* build( int low, int high )
  {
    if( low == high )
      return new Node;
    int mid = ( low + high ) >> 1;
    Node *current = new Node();
    current->left = build( low, mid );
    current->right = build( mid + 1, high );
    return current;
  }

  int query( int qLow, int qHigh, int low, int high, Node *current )
  {
  }

  Node* update(int qPos, int qValue, int low, int high, Node *current)
  {
    if( low == high && qPos == low )
      return new Node( qValue );
    int mid = ( high + low ) >> 1;
    Node *nuevo = new Node( current );
    if( qPos <= mid )
      nuevo->left = update( qPos, qValue, low, mid, current->left );
    else
      nuevo->right = update( qPos, qValue, mid + 1, high, current->right );
    nuevo->val = nuevo->left->val + nuevo->right->val;
    return nuevo;
  }

  Node* update( int qPos, int qValue, Node *root )
  {
    return update( qPos, qValue, 0, this->tam, root );
  }

};

int main()
{
  int n,k,q;
  int data[ 100010 ];
  cin >> n >> k;
  for( int i = 0 ; i < n ; i++ )
    cin >> data[ i ];

  Node *roots[ MAX ];
  // SegmentTree st( data, n, roots[  ] )

  cin >> q;
  while( q-- )
  {

  }
  return 0;
}
