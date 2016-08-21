#include <bits/stdc++.h>

using namespace std;

int mile(int seconds)
{
  int total;
  total = seconds / 30;
  if(seconds%30 >= 0)
    total++;
  return total * 10;
}

int juicie(int seconds)
{
  int total;
  total = seconds / 60;
  if(seconds%60 >= 0)
    total++;
  return total * 15;
}

int main()
{
  int t,cont = 1;
  cin >> t;
  while ( t-- )
  {
    int n,seconds;
    cin >> n;
    int m,j;
    m = j = 0;
    for(int i = 0 ; i < n ; i++)
    {
      cin >> seconds;
      m += mile(seconds);
      j += juicie(seconds);
    }
    printf("Case %d: ",cont);
    if(m == j)
      printf("Mile Juice %d\n",m);
    else if(m < j)
      printf("Mile %d\n",m);
    else
      printf("Juice %d\n",j);
    cont++;
  }

  return 0;
}
