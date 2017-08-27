#include <iostream>
#include <vector>

using namespace std;

#define INF 1e9

unsigned long long inv;

void merge(int arr[], int low, int mid, int high)
{
  int n1 = mid - low + 1;
  int n2 = high - mid;
  vector < int > left( n1+1, 0 );
  vector < int > right( n2+1, 0 );
  for( int i = 0 ; i < n1 ; i++ )
  {
    left[ i ] = arr[ low + i ];
  }
  for( int i = 0 ; i < n2 ; i++ )
  {
    right[ i ] = arr[ mid + i + 1];
  }
  left[ n1 ] = INF;
  right[ n2 ] = INF;
  int i,j;
  i  = j = 0;
  for( int k = low ; k <= high ; k++ )
  {
    if( left[ i ] <= right[ j ] )
    {
      arr[ k ] = left[ i ];
      i++;
    }
    else
    {
      arr[ k ] = right[ j ];
      j++;
      inv  = inv + n1 - i;
    }
  }
}

void mergesort( int arr[], int low , int high )
{
    if( low < high )
    {
      int mid = (low + high) >> 1;
      mergesort( arr, low, mid );
      mergesort( arr, mid + 1, high );
      merge( arr,low, mid, high );
    }
}

int main()
{
  int n;
  ios::sync_with_stdio(0);
  cin.tie(0);
  while( cin >> n && n)
  {
    inv = 0;
    int arr[ n ];
    for( int i = 0 ; i < n ; i++ )
      cin >> arr[ i ];
    mergesort( arr, 0, n-1 );
    // for( int i = 0 ; i < n ; i++ )
    //   cout << arr[ i ] << '\n';
    cout << inv << '\n';
  }
  return 0;
}
