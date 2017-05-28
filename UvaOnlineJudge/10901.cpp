#include <bits/stdc++.h>

using namespace std;

int main()
{
  int c;
  scanf("%d",&c);
  int aa = 0;
  while( c-- )
  {
    int t,m,n;
    if(aa > 0)
      printf("\n");
    aa++;
    scanf("%d%d%d",&n,&t,&m);
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
    int currentTime = 0;
    if(!left.empty())
    {
      if(!right.empty())
      {
        if(left.front() < right.front())
          currentTime += left.front();
      }
      else
      {
        currentTime += left.front();
      }
    }
    int cont = 1;
    while(!left.empty() || !right.empty())
    {

      if(le)
      {
          cont = 0;
          while(!left.empty())
          {
            //printf("IZQUIERDA: %d--%d\t%d\n",currentTime,(int)left.front(),(int)right.front() );
            if(left.front() <= currentTime && cont < n)
            {
              cont++;
              printf("%d\n",currentTime+t);
              left.pop();
            }
            else
              break;
          }
        if(cont != 0)
          le = false;
        if(!right.empty())
          if(right.front() <= currentTime)
            le = false;
      }
      else
      {
          cont = 0;
          while(!right.empty())
          {
          //  printf("DERECHA: %d--%d\t%d\n",currentTime,(int)left.front(),(int)right.front() );
            if(right.front() <= currentTime && cont < n)
            {
              printf("%d\n",currentTime+t);
              cont++;
              right.pop();
            }
            else
              break;
          }
            //printf("DERECHA VACIO: %d--%d\n",currentTime,(int)left.front());
          if(cont != 0)
            le = true;
          if(!left.empty())
            if(left.front() <= currentTime)
              le = true;
      }
      currentTime += t;
    }
  }
  return 0;
}
