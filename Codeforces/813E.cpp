#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

#define MAX 100010
int arr[ MAX ];

typedef struct Node* pNode;

struct Node
{
  pNode left,right;
  int value;
  Node()
  {
    this->value = 0;
    this->left = this->right = NULL;
  }
  Node( pNode newNode )
  {
    this->left = newNode->left;
    this->right = newNode->right;
    this->value = newNode->value;
  }
  Node( int& value )
  {
    this->value = value;
    this->left = this->right = NULL;
  }
};

struct SegmentTree
{
  int tam;


  SegmentTree( int n, Node *&root )
  {
    this->tam = n;
    root = build( 0, n-1 );
  }

  Node* build( int low, int high )
  {
    if( low == high )
      return new Node;
    int mid = (low + high) >> 1;
    Node* current = new Node;
    current->left = build( low , mid );
    current->right = build( mid + 1, high );
    return current;
  }

  int query( int& qLow, int& qHigh, int low, int high, Node *root  )
  {
    if( low >= qLow && high <= qHigh )
      return root->value;
    if( qLow > high || qHigh < low )
      return 0;
    int mid = (low + high) >> 1;
    return query( qLow, qHigh, low, mid, root->left ) + query( qLow, qHigh, mid+1, high, root->right );
  }

  int query( int qLow, int qHigh, Node *root )
  {
    return query( qLow, qHigh, 0, this->tam-1, root );
  }

  Node* update( int &qPos, int &qValue, int low, int high, Node *prev )
  {
    if( low == high && qPos == low )
      return new Node( qValue );

    int mid = (low + high) >> 1;
    Node *newNode = new Node( prev );
    if( qPos <= mid )
      newNode->left = update( qPos, qValue, low, mid, prev->left );
    else
      newNode->right = update( qPos, qValue, mid + 1, high, prev->right );
    newNode->value = newNode->left->value + newNode->right->value;
    return newNode;
  }

  Node* update( int &qPos, int qValue, Node *root )
  {
    return update( qPos, qValue, 0, this->tam-1, root);
  }
};

int main()
{
  int n,k,q,l,r,x,y;
  cin >> n >> k;
  for( int i = 0 ; i < n ; i++ )
    cin >> arr[ i ];

  vector<Node *> roots( n+10 );
  vector < queue < int > > identifiers( MAX, queue<int>() ) ;
  SegmentTree st( MAX, roots[ 0 ] );
  int version = 1;
  for( int i = 0 ; i < n ; i++ )
  {
    if( (int)identifiers[ arr[ i ] ].size() < k )
    {
      identifiers[ arr[ i ] ].push( i );
      roots[ version ] = st.update( i, 1, roots[ version - 1 ] );
    }
    else
    {
      int curr_position = identifiers[ arr[ i ] ].front();
      identifiers[ arr[ i ] ].pop();
      identifiers[ arr[ i ] ].push( i );
      roots[ version ] = st.update( curr_position, 0, roots[ version - 1 ] );
      roots[ version ] = st.update( i, 1, roots[ version ] );
    }
    version++;
  }

  cin >> q;
  int lambda = 0;
  while( q-- )
  {
    cin >> x >> y;
    l = ((x+lambda)%n)+1;
    r = ((y+lambda)%n)+1;
    if( l > r ) swap( l,r );
    lambda = st.query( l - 1, r - 1, roots[ r ] );
    cout << lambda << '\n';
  }

  return 0;
}
