#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  int cases;
  int cont = 1;
  vector < ll > numbers;
  for(int i = 1 ; cont <= 2147483647 ; i++ )
  {
    for(int j = 1 ; j<= i ; j++)
    {
      numbers.push_back( j );
      cont++;
    }
  }
  scanf("%d",&cases);
  while( cases-- )
  {
    ll position;
    scanf("%lld",&position);
    printf("%lld\n",numbers[ position-1 ] );
  }

  return 0;
}
