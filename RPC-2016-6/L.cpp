#include <bits/stdc++.h>

using namespace std;

#define MAX 1e7

typedef long long ll;

int gcd(int a, int b)
{
  if(b == 0) return a;
  else
  return gcd(b, a%b);
}

int combinar(int inicio, vector < int > array, bool first)
{
  int num = 0;
  if(first)
  {

    for(int i = array.size()-1 ; i >= inicio ; i--)
    {
      num *= 10;
      num += array[ i ];
    }
  }
  else
  {
    for(int i = inicio ; i >= 0 ; i--)
    {
      num *= 10;
      num += array[ i ];
    }
  }
  return num;
}


int main()
{
  int n;
  int casos = 1;
  scanf("%d",&n);
  while( n-- )
  {
    int number;
    scanf("%d",&number);
    vector < int > array;
    while( number != 0 )
    {
      array.push_back(number%10);
      number /= 10;
    }
    printf("Ticket #%d:\n",casos++);
    bool band = false;
    for(int i = array.size()-1 ; i >= 1 ; i--)
    {
      int first = combinar(i,array,true);
      int second = combinar(i-1,array,false);
      if(gcd(first,second) == 1)
      {
        printf("%d %d\n",first,second);
        band = true;
        break;
      }
    }
    if(!band)
    {
      printf("Not relative\n");
    }
  }

  return 0;
}
