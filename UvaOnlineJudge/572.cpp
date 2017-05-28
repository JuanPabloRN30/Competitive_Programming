#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector < vector < char > > graph;

int di[] = {-1,-1,-1,0,0,1,1,1};
int dj[] = {-1, 0, 1,-1,1,-1,0,1};
int n,m;

bool in(int currenti , int currentj)
{
  return currenti >= 0 && currenti < n && currentj >= 0 &&  currentj < m;
}

bool bfs( int x, int y )
{
  queue < pair < int , int > > q;
  q.push( make_pair(x,y) );
  while( !q.empty() )
  {
    pair < int , int > current = q.front();
    q.pop();
    for(int i = 0 ; i < 8 ; i++)
    {
      int currenti = di[ i ] + current.first;
      int currentj = dj[ i ] + current.second;
      if( in( currenti,currentj) )
      {
        if( graph[ currenti ][ currentj ] == '@')
        {
          graph[ currenti ][ currentj ] = '*';
          q.push( make_pair( currenti, currentj ) );
        }
      }
    }
  }
  return true;

}

int main()
{
  while( scanf("%d%d",&n,&m) && (n+m) )
  {
    graph.assign( n, vector < char > (m) );
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < m ; j++)
      {
        cin >> graph[ i ][ j ];
      }
    }

    int cont = 0;
    for(int i = 0 ; i < n ; i++)
    {
      for(int j = 0 ; j < m ; j++)
      {
        if( graph[ i ][ j ] == '@' )
        {
          bfs( i, j );
          cont++;
        }
      }
    }
    printf("%d\n",cont);

  }

  return 0;
}
