#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n,m;
  while(true)
  {
    scanf("%d%d",&n,&m);
    bitset<10000000> bs;
    if(!(n+m))
    {
      break;
    }
    int start,end,interval;
    bool band = true;
    for(int i = 0 ; i < n ; i++)
    {
      scanf("%d%d",&start,&end);
      for(int j = start ; j < end ; j++)
      {
        if(bs.test(j))
        {
          band = false;
        }
        bs.set(j,1);
      }
    }
    for(long long i = 0 ; i < m ; i++)
    {
      scanf("%d%d%d",&start,&end,&interval);
      for(long long j = 0 ; j <= 1000000 ; j++)
      {
        for(long long k = start+(j*interval) ; k < end+(j*interval) && k <= 1000000 ; k++)
        {
          if(bs.test(k))
          {
            band = false;
          }
          bs.set(k,1);
        }
      }
    }
    if(band)
      printf("NO CONFLICT\n");
    else
      printf("CONFLICT\n");
  }

  return 0;
}
