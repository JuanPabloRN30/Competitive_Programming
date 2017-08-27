#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_increasing( vector < int > &arr )
{
  for( int i = 1 ; i < (int)arr.size() ; i++ )
    if( arr[ i ] < arr[ i - 1 ] ) return false;
  return true;
}

int main()
{
  int n,k;
  cin >> n >> k;
  vector < int > sequence( n );
  vector < int > numbers( k );
  for( int i = 0 ; i < n ; i++ )
    cin >> sequence[ i ];
  for( int i = 0 ; i < k ; i++ )
    cin >> numbers[ i ];
  sort( numbers.rbegin(), numbers.rend() );
  int indice = 0;
  for( int i = 0 ; i < n ; i++ )
  {
    if( sequence[ i ] == 0 ) sequence[ i ] = numbers[ indice++ ];
  }
  if( is_increasing( sequence ) )
    cout << "No" << '\n';
  else
    cout << "Yes" << '\n';
  return 0;
}
