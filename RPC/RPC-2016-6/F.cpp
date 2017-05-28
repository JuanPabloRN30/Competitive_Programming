#include <bits/stdc++.h>

using namespace std;

#define INF -1e7
typedef vector < int > vi;
typedef long long ll;

int price[ 5 ][ 5005 ];
int M,C = 4;
int memo[ 100000000 ][ 5 ];
int contadores[ 100000000 ][ 5 ];


int shop(int money, int g, ll cont)
{

  if(money < 0 ) return INF;
  if( g == C )
  {
    return M - money;
  }
  if(memo[ money ][ g ] != -1)
  {
    return memo[money][g];
  }
  int ans = -1;
  for(int model = 1 ; model <= price[g][0] ; model++)
    ans = max(ans, shop(money - price[ g ][ model ], g+1, cont));
  return memo[money][g] = ans;
}

int main()
{
  int l,s,m,d,b;
  while(scanf("%d%d%d%d%d",&l,&s,&m,&d,&b) && (l+s+m+d+b))
  {
    M = l;
    ll cont = 0;
    price[ 0 ][ 0 ] = s;
    price[ 1 ][ 0 ] = m;
    price[ 2 ][ 0 ] = d;
    price[ 3 ][ 0 ] = b;
    for(int i = 1 ; i <= s ; i++)
    {
      scanf("%d",&price[ 0 ][ i ]);
    }
    for(int i = 1 ; i <= m ; i++)
    {
      scanf("%d",&price[ 1 ][ i ]);
    }
    for(int i = 1 ; i <= d ; i++)
    {
      scanf("%d",&price[ 2 ][ i ]);
    }
    for(int i = 1 ; i <= b ; i++)
    {
      scanf("%d",&price[ 3 ][ i ]);
    }
    memset(memo, -1, sizeof memo);
    memset(contadores, -1, sizeof contadores);
    shop(l, 0, cont);
    printf("%lld\n",cont);
    cout << endl;

  }

  return 0;
}
