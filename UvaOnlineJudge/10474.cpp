#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int N,Q;
  int cases = 1;
  while(scanf("%d%d",&N,&Q) && (N+Q))
  {
    vector < int > marbles(N,0);
    for(int i = 0 ; i < N ; i++)
    {
      scanf("%d",&marbles[i]);
    }
    sort(marbles.begin(),marbles.end());
    int number;
    printf("CASE# %d:\n",cases++);
    for(int i = 0 ; i < Q ; i++)
    {
      scanf("%d",&number);
      vector < int >::iterator it;
      it = lower_bound(marbles.begin(),marbles.end(),number);
      if(*it == number)
      {
        int position = it-marbles.begin()+1;
        printf("%d found at %d\n",number,position);
      }
      else
      {
        printf("%d not found\n",number);
      }
    }
  }

  return 0;
}
