#include <bits/stdc++.h>

using namespace std;

long long sum( int a1, int an, int n )
{
  return (n * ( a1 + an) ) >> 1;
}

int main()
{
  int a,b;
  cin >> a >> b;
   if( (a&1) && a >= b )
     puts("Valera");
   else
     puts("Vladik");
  return 0;
}
