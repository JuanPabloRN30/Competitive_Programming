#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair < int , int > ii;

vector < vector < int > > tree_bob;
vector < vector < int > > tree_alice;
vector < int > ans_bob,ans_alice;
vector < bool > mark_s;

void bfs( int o, vector < vector < int > > &tree, vector < int > &ans )
{
  queue < ii > q;
  vector < bool > mark( tree.size(), 0 );
  q.push( ii(o,0) );
  mark[ o ] = true;
  while( !q.empty() )
  {
    int current = q.front().first;
    int level = q.front().second;
    q.pop();
    ans[ current ] = level;
    for( int i = 0 ; i < (int)tree[ current ].size() ; i++ )
    {
      if( !mark[ tree[ current ][ i ] ] )
      {
        mark[ tree[ current ][ i ] ] = true;
        q.push( ii(tree[ current ][ i ],level+1) );
      }
    }
  }
}

ii dfs( int current )
{
  mark_s[ current ] = true;
  ii aux = ii(current,ans_alice[ current ]);
  for( int i = 0 ; i < (int)tree_bob[ current ].size() ; i++ )
  {
    int v = tree_bob[ current ][ i ];
    if( !mark_s[ v ] && ans_alice[ v ] > ans_bob[ v ] )
    {
      ii aux2 = dfs( v );
      if( aux.second < aux2.second )
        aux = aux2;
    }
  }
  return aux;
}

int main()
{
  int n,x,o,d;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> x;
  --x;
  tree_bob.assign( n, vector < int > () );
  tree_alice.assign( n, vector < int > () );
  ans_bob.assign( n,0 );
  ans_alice.assign( n,0 );
  mark_s.assign( n, false );
  for( int i = 0 ; i < n-1 ; i++ )
  {
    cin >> o >> d;
    --o;
    --d;
    tree_bob[ o ].push_back( d );
    tree_bob[ d ].push_back( o );
    tree_alice[ o ].push_back( d );
    tree_alice[ d ].push_back( o );
  }
  bfs( x, tree_bob, ans_bob );
  bfs( 0, tree_alice, ans_alice );
  cout << dfs( x ).second * 2<< '\n';

  return 0;
}
