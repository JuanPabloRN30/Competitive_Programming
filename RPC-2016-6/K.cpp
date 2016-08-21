#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  int acum = 0;
  int casos = 1;
  while(scanf("%d",&n) && n)
  {
    acum += n;
    if(acum >= 50 && acum <= 99)
    {
      printf("Input #%d: Sweet!\n",casos);
      acum -= 50;
    }
    else if(acum >= 100)
    {
      printf("Input #%d: Totally Sweet!\n",casos);
      int comprados = acum/50;
      acum -= comprados*50;
    }
    casos++;
  }

  return 0;
}
