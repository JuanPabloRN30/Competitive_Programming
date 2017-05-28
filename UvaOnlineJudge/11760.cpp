#include <bits/stdc++.h>

using namespace std;

int main()
{
  int r,c,n;
  int cont = 1;
  while(true)
  {
    scanf("%d%d%d",&r,&c,&n);
    if(!(r+c+n))
      break;
    bitset<10000> rows;
    bitset<10000> cols;
    int rr,cc;
    bool bandera = false;
    int di[]={0,-1,0,0,1};
    int dj[]={0 ,0,1,-1,0};
    for(int i = 0 ; i < n+1 ; i++)
    {
      scanf("%d%d",&rr,&cc);
      if(i == n)
      {
        for(int j = 0 ; j < 5 ; j++)
        {
          int currenti = di[j]+rr;
          int currentj = dj[j]+cc;
          if((currenti >= 0 && currenti < r) && (currentj >= 0 && currentj < c))
          {
            if(!rows.test(currenti) && !cols.test(currentj))
              bandera = true;
          }
        }
      }
      else
      {
        rows.set(rr,1);
        cols.set(cc,1);
      }
    }
    if(bandera)
      printf("Case %d: Escaped again! More 2D grid problems!\n",cont++ );
    else
      printf("Case %d: Party time! Let's find a restaurant!\n",cont++ );


  }



  return 0;
}
