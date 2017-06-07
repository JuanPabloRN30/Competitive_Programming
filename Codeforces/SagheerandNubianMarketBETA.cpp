#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll cost[ 1000000 ];
ll total_cost[ 1000000 ];
int n;
ll s;

int dp( int index, ll remS )
{
  if( remS <= 0) return 0;
  if( index == n ) return 0;
  if( cost[ index ]* )
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> s;
  for( int i = 0 ; i < n ; i++ )
    cin >> cost[ i ];

  cout << cont << " " << acum << '\n';
  return 0;
}
