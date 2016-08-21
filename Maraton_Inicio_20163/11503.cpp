#include <bits/stdc++.h>

using namespace std;

vector < int > id;
vector < int > sz;

void iniciar( int N )
{
  id.assign(N,0);
  sz.assign(N,1);
  for(int i = 0 ; i < N ; i++)
  {
    id[i] = i;
  }
}

int root(int i)
{
  while( i != id[i] )
  {
    i = id[ i ] = id[ id[ i ] ];
  }
  return i;
}

bool connected(int i , int j)
{
  return root(i) == root(j);
}

void unir(int i , int j)
{
  int p = root(i);
  int q = root(j);
  if( p == q ) return;
  if( sz[ p ] > sz[ q ] )
  {
    id[ q ] = id[ p ];
    sz[ p ] += sz[ q ];
  }
  else
  {
    id[ p ] = id[ q ];
    sz[ q ] += sz[ p ];
  }
}


int main()
{
  int cases;
  scanf("%d",&cases);
  while( cases-- )
  {
    int F;
    string nombre1,nombre2;
    scanf("%d",&F);
    iniciar( 100000 );
    map < string , int > llaves;
    int cont = 0;
    for(int i = 0 ; i < F ; i++)
    {
      cin >> nombre1 >> nombre2;
      if( llaves.find(nombre1) == llaves.end() )
      {
        llaves[ nombre1 ] = cont++;
      }
      if( llaves.find(nombre2) == llaves.end() )
      {
        llaves[ nombre2 ] = cont++;
      }
      unir( llaves[ nombre1 ], llaves[ nombre2 ] );
      printf("%d\n",sz[ root( llaves[ nombre1 ] ) ] );
    }
  }


  return 0;
}
