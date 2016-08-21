#include <cstdio>
#include <iostream>
#include <bitset>
#include <map>

#define INF 99999999
#define foi( i , n , k ) for( int i =  n ; i < k ; ++i)
using namespace std;

int back(bitset<9>&n,bitset<9>&pas,map<pair<int,int>,int>&mp,int ll)
{
  if(n.to_ulong()==511)
  {
    return ll;
  }
  if( mp.find(make_pair(n.to_ulong(),pas.to_ulong()))!=mp.end())
    return mp[make_pair(n.to_ulong(),pas.to_ulong())];
    int men=INF;
  foi( i , 0 , 9 )
  {
    if(!pas[i])
    {
      pas[i]=true;
      n.flip(i);
      if(i+3<9)
        n.flip(i+3);
      if( i-3>=0)
        n.flip(i-3);
      if( (i%3)+1<3)
        n.flip(i+1);
      if( (i%3)-1>=0)
        n.flip(i-1);
      men=min(men,back(n,pas,mp,ll+1));
      if( (i%3)-1>=0)
        n.flip(i-1);
      if( (i%3)+1<3)
        n.flip(i+1);
      if( i-3>=0)
        n.flip(i-3);
      if(i+3<9)
        n.flip(i+3);
      n.flip(i);
      pas[i]=false;
    }
  }
  mp[make_pair(n.to_ulong(),pas.to_ulong())]=men;
  return men;
}

int main()
{
  int t;
  scanf("%d",&t);
  map<pair<int,int>,int> mp;
  while( t-- )
  {
    bitset<9> n,pas;
    char a;
    foi(i , 0 , 9)
    {
      scanf(" %c",&a);
      if(a=='.')
        n.set(i);
    }
    printf("%d\n",back(n,pas,mp,0));
  }
  return 0;
}
