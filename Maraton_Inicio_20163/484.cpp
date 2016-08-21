#include <bits/stdc++.h>

using namespace std;

int main()
{
  int value;
  vector < int > arr;
  while(scanf("%d",&value) != EOF)
  {
    arr.push_back(value);
  }
  vector < bool > ya_imprimi(arr.size(),false);
  for(int i = 0 ; i < (int)arr.size() ; i++)
  {
    int cont = 0;
    for(int j = i ; j < (int)arr.size() ; j++)
    {
      if(!ya_imprimi[ j ] && arr[i] == arr[j])
      {
        ya_imprimi[ j ] = true;
        cont++;
      }
    }
    if( cont)
      printf("%d %d\n",arr[ i ],cont);
  }


  return 0;
}
