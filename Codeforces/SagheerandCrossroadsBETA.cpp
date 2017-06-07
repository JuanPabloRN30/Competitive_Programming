#include <bits/stdc++.h>

using namespace std;

struct road
{
  int l,s,r,p;
};


int main()
{
  road r[ 5 ];
  for( int i = 0 ; i < 4 ; i++ )
    cin >> r[ i ].l >> r[ i ].s >> r[ i ].r >> r[ i ].p;

  bool flag = false;

  if( r[ 0 ].p )
  {
    if( r[ 1 ].l || r[ 2 ].s || r[ 3 ].r )
      flag = true;
  }
  if( r[ 1 ].p )
  {
    if( r[ 0 ].r || r[ 2 ].l || r[ 3 ].s )
      flag = true;
  }
  if( r[ 2 ].p )
  {
    if( r[ 0 ].s || r[ 1 ].r || r[ 3 ].l )
      flag = true;
  }
  if( r[ 3 ].p )
  {
    if( r[ 0 ].l || r[ 1 ].s || r[ 2 ].r )
      flag = true;
  }
  if( flag )
    puts("YES");
  else
    puts("NO");

  return 0;
}
