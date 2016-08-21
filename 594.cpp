#include <bits/stdc++.h>

using namespace std;

int main()
{
  unsigned int n;
  while(cin >> n)
  {
    unsigned char * var = (unsigned char * ) &n;
    printf("%d converts to %d\n",n, (int) ((var[0] << 24) + (var [1] << 16) + (var[2] << 8) + var[3]));
  }
  return 0;
}
