#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define INF 1e9
typedef long long ll;
typedef pair < int , int > ii;

struct data
{
  int pow_2;
  int pow_5;
  char path_2;
  char path_5;

  data()
  {
    pow_2 = pow_5 = INF;
  }

  void toString()
  {
    printf("pow2 = %d - pow5 = %d\t\t",pow_2,pow_5);
  }
};

ll matriz[ 1010 ][ 1010 ];
data dp[ 1010 ][ 1010 ];
int n;

int fact( ll n , ll pf )
{
  int cont = 0;
  while( n%pf == 0 ){
    cont++;
    n/= pf;
  }
  return cont;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  memset( matriz, 0 , sizeof matriz );
  bool have_zero = false;
  ii position_zero;
  cin >> n;
  for( int i = 0 ; i < n ; i++ )
  {
    for( int j = 0 ; j < n ; j++ )
    {
      cin >> matriz[ i ][ j ];
      if( matriz[ i ][ j ] == 0 )
      {
        matriz[ i ][ j ] = 10;
        have_zero = true;
        position_zero = ii( i,j );
      }
    }
  }

  dp[ 0 ][ 1 ].pow_2 = dp[ 0 ][ 1 ].pow_5 = 0;
  for( int i = 1 ; i<= n ; i++ )
  {
    for( int j = 1 ; j<= n ; j++ )
    {
      int fact_2 = fact( matriz[ i-1 ][ j-1 ], 2LL );
      int fact_5 = fact( matriz[ i-1 ][ j-1 ], 5LL );
      if( dp[ i - 1 ][ j ].pow_2 < dp[ i ][ j - 1 ].pow_2 )
      {
        dp[ i ][ j ].pow_2 = dp[ i - 1 ][ j ].pow_2 + fact_2;
        dp[ i ][ j ].path_2 = 'D';
      }
      else
      {
        dp[ i ][ j ].pow_2 = dp[ i ][ j-1 ].pow_2 + fact_2;
        dp[ i ][ j ].path_2 = 'R';
      }

      if( dp[ i - 1 ][ j ].pow_5 < dp[ i ][ j - 1 ].pow_5 )
      {
        dp[ i ][ j ].pow_5 = dp[ i - 1 ][ j ].pow_5 + fact_5;
        dp[ i ][ j ].path_5 = 'D';
      }
      else
      {
        dp[ i ][ j ].pow_5 = dp[ i ][ j-1 ].pow_5 + fact_5;
        dp[ i ][ j ].path_5 = 'R';
      }
    }
  }
  string ans_path = "";
  {
    int i = n;
    int j = n;
    bool path_2 = true;
    if( dp[ i ][ j ].pow_5 < dp[ i ][ j ].pow_2 )
      path_2 = false;
    while( i != 1 || j != 1 )
    {
      if( path_2 )
      {
        ans_path += dp[ i ][ j ].path_2;
        if( dp[ i ][ j ].path_2 == 'D' ) i--;
        else                             j--;
      }
      else
      {
        ans_path += dp[ i ][ j ].path_5;
        if( dp[ i ][ j ].path_5 == 'D' ) i--;
        else                             j--;
      }
    }
  }
  int ans = min( dp[ n ][ n ].pow_2, dp[ n ][ n ].pow_5 );
  if( ans > 1 && have_zero )
  {
    cout << 1 << '\n';
    for( int i = 0 ; i < position_zero.first ; i++ )
      cout << 'D';
    for( int i = 0 ; i < n-1 ; i++ )
      cout << 'R';
    for( int i = 0 ; i < n - position_zero.first - 1 ; i++ )
      cout << 'D';
    cout << '\n';
  }
  else
  {
    reverse( ans_path.begin(), ans_path.end() );
    cout << ans << '\n';
    cout << ans_path << '\n';
  }
  return 0;
}
