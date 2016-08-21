#include <bits/stdc++.h>

using namespace std;

int main()
{
  int c;
  scanf("%d",&c);
  while( c-- )
  {
    int l,m;
    scanf("%d%d",&l,&m);
    queue < int > left;
    queue < int > right;
    int value;
    string direction;
    for(int i = 0 ; i < m ; i++)
    {
      cin >> value >> direction;
      if(direction == "left")
        left.push(value);
      else
        right.push(value);
    }
    bool le = true;
    l = l*100;
    int cont = 0;
    while(!left.empty() || !right.empty())
    {
      if(le)
      {
        int acum = 0;
        while(!left.empty())
        {
          if(acum + left.front() < l)
          {
            acum += left.front();
            left.pop();
          }
          else
            break;
        }
        le = false;
      }
      else
      {
        int acum = 0;
        while(!right.empty())
        {
          if(acum + right.front() < l)
          {
            acum += right.front();
            right.pop();
          }
          else
            break;
        }
        le = true;
      }
      cont++;
    }
    printf("%d\n",cont);
  }

  return 0;
}
