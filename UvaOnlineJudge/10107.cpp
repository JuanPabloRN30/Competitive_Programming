#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
  int n;
  vector < int > arr;
  while( scanf("%d",&n) != EOF )
  {
    arr.push_back( n );
    sort( arr.begin(), arr.end() );
    if( arr.size() == 1 )
      printf("%d\n",n);
    else
    {
      if( arr.size() & 1 )
        printf("%d\n",arr[ ceil(arr.size()/2) ] );
      else
        printf("%d\n",(arr[ ceil( arr.size()/2 ) ] + arr[ ceil( arr.size()/2 ) - 1 ])/2  );
    }
  }

  return 0;
}
