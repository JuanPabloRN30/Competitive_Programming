#include <bits/stdc++.h>

using namespace std;

vector < int > size_cd;

int n;
const int INF = -1e9;
int ans,ans1;

void backtrack( int pos, int llevo, int mascara)
{
  if( pos == (int)size_cd.size() )
  {
    if( llevo <= n )
    {
        if( llevo >= ans )
        {
          ans = llevo;
          ans1 = mascara;
        }
    }
    return ;
  }
  if( llevo > n )
    return ;
  backtrack( pos+1,llevo, mascara);
  backtrack( pos+1,llevo+size_cd[ pos ], mascara | (1 << pos)  );
}

int main()
{
  int m;
  while( scanf("%d%d",&n,&m) != EOF )
  {
    size_cd.assign( m,0 );
    ans = 0;
    for( int i = 0 ; i < m ; i++ )
    {
      scanf("%d",&size_cd[ i ]);
    }
    backtrack(0,0,0);
    for( int i = 0 ; i < m ; i++ )
    {
      if( (ans1 >> i) & 1 )
        printf("%d ",size_cd[ i ]);
    }
    printf("sum:%d\n",ans);
  }
  return 0;
}
