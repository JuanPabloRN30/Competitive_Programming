#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
  int N,Q,number;
  scanf("%d",&N);
  vector < int > numbers(N,0);
  vector < int >::iterator lower,upper;
  for(int i = 0 ; i < N ; i++)
  {
    scanf("%d",&numbers[i]);
  }
  scanf("%d",&Q);
  for(int i = 0 ; i < Q ; i++)
  {
    scanf("%d",&number);
    lower = lower_bound(numbers.begin(),numbers.end(),number);
    upper = upper_bound(numbers.begin(),numbers.end(),number);
    if(lower == numbers.end())
    {
      if(numbers[ numbers.size()-1 ] < number)
      printf("%d ",numbers[ numbers.size()-1 ]);
      else
      printf("X ");
    }
    else
    {
      if((lower-numbers.begin())-1 >= 0)
      {
        printf("%d ",*(lower-1));
      }
      else
        printf("X ");
    }
    if(upper == numbers.end())
    printf("X\n");
    else
    printf("%d\n",*upper);
  }

  return 0;
}
