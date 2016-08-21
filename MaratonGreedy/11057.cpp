#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  int N;
  while(scanf("%d",&N) != EOF)
  {
    vector < int > numbers(N,0);
    int M;
    for(int i = 0 ; i < N ; i++)
    {
      scanf("%d",&numbers[ i ]);
    }
    scanf("%d",&M);
    sort(numbers.begin(),numbers.end());

    int menor = 1e9;
    pair < int , int > res;
    for(int i = 0 ; i < N && numbers[i] < M ; i++)
    {
      vector < int >::iterator it;
      it = lower_bound(numbers.begin(),numbers.end(),M-numbers[i]);
      if((*it) == M-numbers[i])
      {
        if( abs((M-numbers[i])-numbers[i]) < menor )
        {
          menor = abs((M-numbers[i])-numbers[i]);
          res = make_pair(numbers[i],(M-numbers[i]));
        }
      }
    }
    printf("Peter should buy books whose prices are %d and %d.\n",res.first,res.second);
    printf("\n");
  }

  return 0;
}
