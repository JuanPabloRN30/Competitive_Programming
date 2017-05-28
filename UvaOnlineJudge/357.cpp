#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll memo[ 30010 ][ 5 ];
ll a[ 5 ];

ll dp(int rest, int pos)
{

  if( pos == 5 )
    return 0;
  if( rest < 0 )
    return 0;
  if( rest == 0 )
    return 1;
  if( memo[ rest ][ pos ] != -1 )
    return memo[ rest ][ pos ];
  return memo[ rest ][ pos ] = dp( rest-a[pos],pos ) + dp( rest, pos+1 );

}


int main()
{
  int n;
  a[ 0 ] = 1;
  a[ 1 ] = 5;
  a[ 2 ] = 10;
  a[ 3 ] = 25;
  a[ 4 ] = 50;
  memset( memo,-1,sizeof(memo) );
  while( scanf("%d",&n) != EOF )
  {
    ll result = dp( n, 0 );
    if( result == 1 )
      printf("There is only 1 way to produce %d cents change.\n",n);
    else
      printf("There are %lld ways to produce %d cents change.\n",result,n);
  }


  return 0;
}
