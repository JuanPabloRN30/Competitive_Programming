#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int cases;
  scanf("%d",&cases);
  while( cases-- )
  {
    int d,i;
    scanf("%d%d",&d,&i);
    int inicio = 0;
    inicio = 0;
    int nivel = 1;
    vector < int > numbers;
    for(int x = (1<<(d-1)) ; x< (1<<d) ; x++)
    {
      numbers.push_back(x);
    }
    //printf("%d - %d\n",numbers[ inicio ].number, inicio);*/
  }
  scanf("%d",&cases);

  return 0;
}
